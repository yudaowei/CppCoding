#include "smartPointerTest.h"
using namespace std;

namespace SmartPointerNamespace{

class FileDeleter{
private:
    string filename;
public:
    FileDeleter(const string& fn) : filename(fn){

    }
    void operator() (ofstream* fp){
        fp->close();
        cout << "remove" << endl;
        remove(filename.c_str());
    }
};
class Person : public enable_shared_from_this<Person>{
public:
    string name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;
    vector<weak_ptr<Person>> kids;

    Person(const string& n, shared_ptr<Person> m = nullptr, 
            shared_ptr<Person> f = nullptr)
    : name(n), mother(m), father(f){

    }
    void setParentsAndTheirKids(shared_ptr<Person> m = nullptr, 
                                shared_ptr<Person> f = nullptr){
        mother = m;
        father = f;
        if(m != nullptr){
            m->kids.push_back(shared_from_this());
        }
        if(f != nullptr){
            f->kids.push_back(shared_from_this());
        }
    }
    ~Person(){
        cout << "delete" << name << endl;
    }
};
static shared_ptr<Person> initFamily(const string& name)
{
    shared_ptr<Person> mom(new Person(name+"'s mom"));
    shared_ptr<Person> dad(new Person(name+"'s dad"));
    shared_ptr<Person> kid(new Person(name, mom, dad));
    // mom->kids.push_back(kid);
    // dad->kids.push_back(kid);
    kid->setParentsAndTheirKids(mom, dad);
    return kid;
}
static void weakPtrTest()
{
    shared_ptr<Person> p = initFamily("nico");

    cout << "nico's family exists" << endl;
    cout << "- nico is  shared" << p.use_count() << "times" << endl;
    cout << "- name of 1st kid of nico's mom: " 
            << (p->mother->kids[0].expired()? "":p->mother->kids[0].lock()->name) << endl;
    p = initFamily("jim");
    cout << "jim's family exists" << endl;
}
static void sharedPtrTest()
{
    // shared_ptr<string> pNico{new string("nico")};
    //指定销毁器 Delete
    shared_ptr<string> pNico{new string("nico"), 
                                [](string* p) noexcept {
                                    cout << "delete " << *p << endl;
                                    delete p;
                                }};
    shared_ptr<string> pJutta = make_shared<string>("jutta");//效率更高

    (*pNico)[0] = 'N';
    pJutta->replace(0, 1, "J");

    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);

    for(auto ptr : whoMadeCoffee){
        cout << *ptr << " ";
    }
    cout << endl;

    *pNico = "Nicolai";

    for(auto ptr : whoMadeCoffee){
        cout << *ptr << " ";
    }
    cout << endl;
    pNico = nullptr;
    whoMadeCoffee.resize(2);
    cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;

    //对付array
    shared_ptr<int> p{new int[10], 
                        [](int *p)noexcept{
                            delete[] p;
                        }};
    shared_ptr<int> p2{new int[10], default_delete<int[]>()};

    //制定自己的析构策略, 即除了释放内存还需做其他事时
    shared_ptr<ofstream> fp(new ofstream("tempfile.txt"), FileDeleter("tempfile.txt"));

    //weak_ptr
    weakPtrTest();
}
static void uniquePtrTest()
{
    //unique_ptr独占式的指针
    unique_ptr<string> pNico{new string("nico")};
    unique_ptr<string> pJutta = make_unique<string>("jutta");

    cout << "unique " << *pNico << endl;
    string* str = pNico.release();
    cout << "string " << *str << endl;

    unique_ptr<string> pt = move(pNico);
    cout << (pNico==nullptr) << endl;
    cout << "pt " << (pt == nullptr) << endl;

}
void smartPointerTest()
{
    sharedPtrTest();
    uniquePtrTest();
}

}