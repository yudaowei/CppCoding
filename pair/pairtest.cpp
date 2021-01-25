#include "pairtest.h"
#include <tuple>
template<typename T1, typename T2>
std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& arg1)
{
    return os << "[" << arg1.first << "," << arg1.second << "]";
}

namespace PairTest_nameSpace{
class A{
public:
    A(){cc = 0;};
    A(const int arg):cc(arg){}
    A(const A& arg){
        cc = arg.cc;
    }
    int getvalue() const { return cc; }
private:
    int cc;
};
class Foo{
public:
    Foo(std::tuple<int, float>){
        std::cout << "Foo::Foo(tuple)" << std::endl;
    }
    template<typename... Args>
    Foo(Args... args){
        std::cout << "Foo::Foo(args...)" << std::endl;
    }
};
void pairTest()
{
    // std::pair<int, char> temp{12, 'a'};
    // std::cout << std::get<0>(temp) << "," << temp.second << std::endl;
    // std::cout << temp << std::endl;
    // std::cout << std::tuple_size<std::pair<int, char>>::value << std::endl;
    // std::tuple_element<0, std::pair<int, char>>::type a{1};
    // std::cout << a << std::endl;
    // A xy(10);
    // std::pair<A, int> x;
    // std::cout << x << std::endl;
    std::tuple<int, float> t(1, 2.22);
    std::pair<int, Foo> p1(42, t);
    std::pair<int, Foo> p2(std::piecewise_construct, std::make_tuple(42), t);
    std::cout << std::get<0>(p2) << std::endl;
}

}
std::ostream& operator << (std::ostream& os, const PairTest_nameSpace::A& arg)
{
    return os << arg.getvalue();
}