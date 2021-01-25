#include "tupletest.h"
using namespace std;

namespace tupleTest_nameSpace{

void tupletest()
{
    // tuple<int, int> test(move(make_pair(11, 22)));
    using TT = tuple<string, int, int, complex<double>>;
    TT t;
    tuple<int, float, string> t1(41, 6.3, "nico");

    // cout << get<0>(t1) << " ";
    // cout << get<1>(t1) << " ";
    // cout << get<2>(t1) << " ";
    // cout << endl;

    auto t2 = make_tuple(22, 44, "nico");
    get<1>(t1) = get<1>(t2);

    int temp;
    string str;
    std::tie(temp, std::ignore, str) = t1;
    cout << temp << "  " << str << endl;

    cout << tuple_size<TT>::value << endl;
    cout << t1 << endl;
    
}

}