#include "smartPointerTest.h"
using namespace std;

namespace SmartPointerNamespace{

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
}
static void uniquePtrTest()
{

}
void smartPointerTest()
{
    sharedPtrTest();
    uniquePtrTest();
}

}