#include <iostream>
#include <bitset>
#include <utility>
#include "pair/pairtest.h"
#include "tuple/tupletest.h"
#include "exception/exceptiontest.h"
#include "smartPointer/smartPointerTest.h"
void printX()
{

}
template<typename T, typename... Types>
void printX(const T& arg, const Types&... args)
{
    std::cout << arg << std::endl;
    printX(args...);
}

int main(int argc, char*argv[])
{
    // PairTest_nameSpace::pairTest();
    // ExceptNameSpace::exceptTest();
    // tupleTest_nameSpace::tupletest();
    SmartPointerNamespace::smartPointerTest();
    return 0;
}
