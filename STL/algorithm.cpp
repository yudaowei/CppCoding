#include "container.h"
using std::cout;
using std::endl;

namespace AlgorithmNamespace{

static void simpleAlg()
{
    auto algo1 = [](){
        std::vector<int> coll = {2, 5, 4, 1, 6, 3};
        auto minpos = std::min_element(coll.cbegin(), coll.cend());
        cout << "min: " << *minpos << endl;
        auto maxpos = std::max_element(coll.cbegin(), coll.cend());
        cout << "max: " << *maxpos << endl;

        std::sort(coll.begin(), coll.end());

        auto pos3 = std::find(coll.begin(), coll.end(), 3);

        std::reverse(pos3, coll.end());

        for(auto &elem : coll){
            cout << elem << " ";
        }
        cout << endl;
    };
    algo1();
}
/*
 *  更易型算法  
 *  会对元素重排或者修改的算法,会改动标的区间 
 */
static void manipulatingAlgorithm()
{
    auto remove1 = [](){
        std::list<int> coll;
        for(int i=1; i<=6; ++i){
            coll.push_back(i);
            coll.push_front(i);
        }
        cout <<"pre :";
        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
        std::remove(coll.begin(), coll.end(), 3);
        cout << "post: ";
        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
        /*
         *  pre : 6 5 4 3 2 1 1 2 3 4 5 6
         *  post: 6 5 4 2 1 1 2 4 5 6 5 6
         */
    };
    auto remove2 = [](){
        std::list<int> coll;
        for(int i=1; i<=6; ++i){
            coll.push_back(i);
            coll.push_front(i);
        }
        cout <<"pre :";
        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
        //返回一个新的结尾标识
        std::list<int>::iterator end = std::remove(coll.begin(), coll.end(), 3);
        cout << "post: ";
        std::copy(coll.begin(), end, std::ostream_iterator<int>(cout, " "));
        cout << endl;
        cout << "number of remove elements: " << std::distance(end, coll.end()) << endl;
        coll.erase(end, coll.end());
        /*
         * 一步到位: coll.erase(std::remove(coll.begin(), coll.end(), 3), coll.end());
         * 这种方法性能较差, 调用成员函数coll.remove(3);性能较好
         */
        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    };
    /*
     * pre :6 5 4 3 2 1 1 2 3 4 5 6
     * post: 6 5 4 2 1 1 2 4 5 6
     * number of remove elements: 2
     * 6 5 4 2 1 1 2 4 5 6
     */
    
    /*
     * 更易关联式和无序容器
     * 更易型算法不得以关联/无序容器为目标, 会打乱其次序的维护, 只能调用其成员函数
     */
    auto remove3 = [](){
        std::set<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(cout, " "));
        cout << endl;

        int num = coll.erase(3);
        cout << "number of remove elements: " << num << endl;

        std::copy(coll.cbegin(), coll.cend(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    };
    /*
     *  以函数作为实参的算法 for_each()
     */
    auto foreach1 = [](){
        auto print = [](int elem){
            cout << elem << " ";
        };
        std::vector<int> coll;

        for(int i=1; i<=10; ++i){
            coll.push_back(i);
        }
        std::for_each(coll.cbegin(), coll.cend(), print);
        cout << endl;
    };
    /*单参判断*/
    auto prime1 = [](){
        /*判断是否为质数*/
        auto isPrime = [](int number)->bool{
            number = abs(number);
            if(number == 0 || number == 1){
                return false;
            }
            int divisor;
            for(divisor = number/2; number%divisor != 0; --divisor){
                ;
            }
            return divisor == 1;
        };
        std::list<int> coll;
        for(int i=24; i<=30; ++i){
            coll.push_back(i);
        }
        auto pos = find_if(coll.cbegin(), coll.cend(), isPrime);
        if(pos != coll.end()){
            cout << *pos << "is first prime number found" << endl;
        }else{
            cout << "no prime number found" << endl;
        }
    };
    /*双参判断*/
    auto sort1 = [](){

        auto personSortCriterion = [](const int p1, const int p2){
            return p1 < p2 ;
        };
        std::deque<int> coll;
        std::sort(coll.begin(), coll.end(), personSortCriterion);
    };
}
void algorithmTest()
{
    // simpleAlg();
    manipulatingAlgorithm();
}

}