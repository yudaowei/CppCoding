#include "typetraittest.h"
using namespace std;
namespace TypeTraitsNamespace{
template<typename T>
static void foo_impl(const T& val, std::true_type)
{
    cout << "foo() called for pointer to " << *val << endl;
}
template<typename T>
static void foo_impl(const T& val, std::false_type)
{
    cout << "foo() called for value to " << val << endl;
}
template<typename T>
static void foo(const T& val)
{
    foo_impl(val, is_pointer<T>());
}

void typeTraitsTest()
{
    int* p{new int(2)};
    foo(p);
    delete p;
}

}