#ifndef __PAIRTEST_H__
#define __PAIRTEST_H__
#include <iostream>
#include <utility>

template<typename T1, typename T2>
std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& arg1);

namespace PairTest_nameSpace{
class A;
class Foo;
void pairTest();
}

std::ostream& operator << (std::ostream& os, const PairTest_nameSpace::A& arg);


#endif