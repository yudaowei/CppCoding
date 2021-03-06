#include "container.h"
#include "../print.hpp"
#include <cstring>
using std::cout;
using std::endl;

namespace ArrayNamespace{
/*
 *  Array运用实例 
 */
void arrayTest()
{
    /*array当做C-Style Array*/
    std::array<char, 41> a;
    strcpy(&a[0], "hello, world");
    printf("%s\n", &a[0]);
    /*array提供tuple接口*/
    /*
    using  FiveStrings = std::array<std::string, 5>;
    FiveStrings a = {"hello", "nico", "how", "are", "you"};
    std::tuple_size<FiveStrings>::value; //5
    std::tuple_element<1, FiveStrings>::type //std::string
    std::get<1>(a) ; // "nico"
    */
    std::array<int, 10> a = {11, 22, 33, 44};
    PRINT_ELEMENTS(a);
    a.back() = 99999;
    a[a.size()-2] = 42;
    PRINT_ELEMENTS(a);
    cout << "sum" << std::accumulate(a.begin(), a.end(), 0) << endl;
    std::transform(a.begin(), a.end(), a.begin(), std::negate<int>());
    PRINT_ELEMENTS(a);
}

}