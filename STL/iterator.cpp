#include "container.h"
using std::cout;
using std::endl;

namespace IteratorNamespace{

void iteratorTest()
{
/*
 *  安插型迭代器 std::back_inserter std::front_inserter std::inserter
 *  算法以安插方式运作, 而非覆写方式, 可解决"目标空间不足"问题
 */
    auto copy2 = [](){
        std::list<int> coll1 = {1,2,3,4,5,6,7,8,9};

        std::vector<int> coll2;
        std::copy(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2));

        std::deque<int> coll3;
        std::copy(coll1.cbegin(), coll1.cend(), std::front_inserter(coll3));

        std::set<int> coll4;
        std::copy(coll1.cbegin(), coll1.cend(), std::inserter(coll4, coll4.begin()));
    };

/*
 *  串流迭代器  istream_iterator
 *  I/O流的一种抽象集合
 */
    auto ioiter1 = [](){
        std::vector<std::string> coll;
        /*
         *  read all words from the standard input
         *  source: all strings until end-of-file
         *  destination: coll(inserting)
         */
        std::copy(std::istream_iterator<std::string>(std::cin),//start of source
                  std::istream_iterator<std::string>(),        //end of source
                  std::back_inserter(coll));

        std::sort(coll.begin(), coll.end());

        std::unique_copy(coll.cbegin(), coll.cend(), 
                        std::ostream_iterator<std::string>(cout, "\n"));
    };
/*
 *  反向迭代器  Reverse_Iterator
 *  所有提供双向或随机访问迭代器的容器都可以通过 rbegin()/crbegin()), rend()/crend() 返回反向迭代器
 *  reverse_iterator可造成算法逆向操作, 内部递增操作符调用转换为递减
 */
    auto reviter1 = [](){
        std::vector<int> coll;
        for(int i =1; i<=9; ++i){
            coll.push_back(i);
        }
        //逆向遍历
        std::copy(coll.crbegin(), coll.crend(), std::ostream_iterator<int>(cout, " "));
        cout << endl;
    };
    reviter1();
/*
 *  搬移迭代器 Move_Iterator
 *  对一个容器的元素搬移到另一个容器中, 以减少复制次数提升程序效率
 */
}

}