#include "container.h"
#include <functional>
#include "../print.hpp"
using namespace std::placeholders;

namespace FunctionOBJNamespace{

/*
 *  调用stl预定义函数对象 <functional>
 */
static void fo1()
{
    std::deque<int> coll = {1,2,3,5,7,11,13,17,19};
    PRINT_ELEMENTS(coll, "initialized: ");
    std::transform(coll.cbegin(), coll.cend(),
        coll.begin(),
        std::negate<int>());
    PRINT_ELEMENTS(coll, "negated: ");
    std::transform(coll.cbegin(), coll.cend(),
        coll.cbegin(),
        coll.begin(),
        std::multiplies<int>());
    PRINT_ELEMENTS(coll, "squared: ");
}
/*
 *  Binder函数适配器
 * 将预定义的函数对象和其他数值结合为一体
 */
static void bind1()
{
    std::set<int, std::greater<int>> coll1 = {1,2,3,4,5,6,7,8,9};
    std::deque<int> coll2;

    PRINT_ELEMENTS(coll1, "initialized: ");

    std::transform(coll1.cbegin(), coll1.cend(),
        std::back_inserter(coll2),
        std::bind(std::multiplies<int>(), _1, 10));
    PRINT_ELEMENTS(coll2, "transformed: ");

    std::replace_if(coll2.begin(), coll2.end(),
        std::bind(std::equal_to<int>(), _1, 70),
        42);
    PRINT_ELEMENTS(coll2, "replaced: ");
    coll2.erase(std::remove_if(coll2.begin(), coll2.end(), 
                                std::bind(std::logical_and<bool>(), 
                                            std::bind(std::greater_equal<int>(), _1, 50), 
                                            std::bind(std::less_equal<int>(), _1, 80))), 
                coll2.end());

    PRINT_ELEMENTS(coll2, "removed: ");
}
void functionOBJTest()
{
    bind1();
}

}