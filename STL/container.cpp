#include "container.h"
using std::cout;
using std::endl;
namespace ContainerNamespace{
/*
 *  序列式容器 
 */
static void sequenceContainerTest()
{
    /*
     *  vector容器 动态数组 随机访问 
     */
    auto vectorTest = [](){
        cout << "Vector: " << endl;
        std::vector<int> coll;

        for(int i=1; i<=6; ++i){
            coll.push_back(i);
        }

        for(int i=0; i<coll.size(); ++i){
            cout << coll[i] << " ";
        }
        cout << endl;
    };
    /*
     *  deque容器 双向增长的动态数组
     */
    auto dequeTest = [](){
        cout << "Deque: " << endl;
        std::deque<float> coll;

        for(int i=1; i<=6; ++i){
            coll.push_front(i*1.1);
        }
        for(int i=0; i<coll.size(); ++i){
            cout << coll[i] << " ";
        }
        cout << endl;
    };
    /*
     *  array容器 固定大小的数组 随机访问
     */
    auto arrayTest = [](){
        cout << "Array: " << endl;
        std::array<std::string, 5> coll = {"hello", "world"};
        for(int i=0; i<coll.size(); ++i){
            cout << i << ": " << coll[i] << endl;
        }
    };
    /*
     *  list容器 双向链表 安插和删除很快 不提供随机访问
     *  forward_list容器 单项链表 
     */
    auto listTest = [](){
        cout << "List:" << endl;
        std::list<char> coll;

        for(char c='a'; c<='z'; ++c){
            coll.push_back(c);
        }
        for(std::list<char>::const_iterator pos=coll.cbegin(); pos != coll.end(); ++pos){
            cout << *pos << ' ';
        }
        cout << endl;

        cout << "Forward_list: " << endl;
        std::forward_list<long> cll = {2, 3, 5, 7, 11, 13, 17};
        cll.resize(9);
        cll.resize(10, 99);
        for(const auto elem : cll){
            cout << elem << " ";
        }
        cout << endl;
    };
    vectorTest();
    dequeTest();
    arrayTest();
    listTest();
}
/*
 *  关联式容器 二叉树实现 左子树比父节点小右子树比父节点大  查找很快
 */
static void associativeContainerTest()
{
    /*
     *  set容器 自动排序 不重复
     *  multiset容器 自动排序 可重复
     */
    auto setTest = [](){
        cout << "Multiset:" << endl;
        std::multiset<std::string> cities {
            "Braunschweig", "Hanover", "Frankfurt", "New York",
            "CHicago", "Toronto", "Pairs", "Frankfurt"
        };
        for(const auto& elem : cities){
            cout << elem << " ";
        }
        cout << endl;
        
        cities.insert({"London", "Munich", "Hanover", "Braunschweig"});

        for(const auto& elem : cities){
            cout << elem << " ";
        }
        cout << endl;
    };

    /*
     *  map容器 key/value对 key不重复 以key来排序
     *  multimap容器  key可重复
     */
    auto mapTest = [](){
        cout << "Multimap:" << endl;
        std::multimap<int, std::string> coll;
        coll = { 
            {5, "tagged"},
            {2, "a"},
            {1, "this"},
            {4, "of"},
            {6, "strings"},
            {1, "is"},
            {3, "multimap"}
         };
         for(auto elem : coll){
             cout << elem.second << " ";
         }
         cout << endl;
    };

    setTest();
    mapTest();
}
/*
 *  无序容器  哈希表实现 查找特定值取的速度决于hash函数的优秀程度
 */
static void unorderedContainerTest()
{
    /*
     *  unorder Set/Multiset 
     */
    auto unorderSet = [](){
        cout << "UnorderMultiset:" << endl;
        std::unordered_multiset<std::string> cities {
            "Braunschweig", "Hanover", "Frankfurt", "New York",
            "CHicago", "Toronto", "Pairs", "Frankfurt"
        };
        for(const auto& elem : cities){
            cout << elem << " ";
        }
        cout << endl;
        
        cities.insert({"London", "Munich", "Hanover", "Braunschweig"});

        for(const auto& elem : cities){
            cout << elem << " ";
        }
        cout << endl;        
    };
    /*
     *  unorder Map/Multimap
     */
    auto unorderMap = [](){
        cout << "UnorderMap:" << endl;
        std::unordered_map<std::string, double> coll {
            {"tim", 9.9},
            {"struppi", 11.77}
        };

        for(std::pair<const std::string, double>& elem : coll){
            elem.second *= elem.second;
        }
        for(const auto& elem : coll){
            cout << elem.first << " : " << elem.second << endl;
        }
    };
    unorderSet();
    unorderMap();
}
void containerTest()
{
    sequenceContainerTest();
    associativeContainerTest();
    unorderedContainerTest();
}

}