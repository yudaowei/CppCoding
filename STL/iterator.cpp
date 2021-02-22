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
}

}