#include "chronotest.h"
using std::cout;
using std::endl;
using namespace std::chrono;
namespace ChronoNamespace{
template<typename V, typename R>
std::ostream& operator<<(std::ostream& s, const std::chrono::duration<V, R>& d)
{
    return s << d.count() << " of " << R::num << "/" << R::den << "]";
}
void chronoTest()
{
    std::chrono::duration<int> twentySeconds(20);//20s
    std::chrono::duration<double, std::ratio<60>> halfAMinute(0.5);
    std::chrono::duration<long, std::ratio<1,1000>> oneMillisecond(1);
    /*
    std::chrono::nanoseconds	
    std::chrono::microseconds	
    std::chrono::milliseconds	
    std::chrono::seconds	
    std::chrono::minutes	
    std::chrono::hours	
    std::chrono::days (C++20 起)	
    std::chrono::weeks (C++20 起)	
    std::chrono::months (C++20 起)	
    std::chrono::years (C++20 起)
    */
    std::chrono::seconds twoSecounds(2);//2s
    std::chrono::hours oneHour(1);// 1h

    duration<int, std::ratio<1,3>> d1(1);
    duration<int, std::ratio<1,5>> d2(2);
    auto d3 = d1 + d2; // same duartion<int, std::ratio<1,15>> d3(11);
    cout << d3.count() << endl;//输出当前tick的数量

    milliseconds ms(7255042);
    hours hh = duration_cast<hours>(ms);
    minutes mm = duration_cast<minutes>(ms % hours(1));
    seconds ss = duration_cast<seconds>(ms % minutes(1));
    milliseconds msec = duration_cast<milliseconds>(ms % seconds(1));

    cout << "raw: " << hh << "::" << mm << "::" << ss << "::" << msec << endl;
    cout << "     " << std::setfill('0') 
         << std::setw(2) << hh.count() << "::"
         << std::setw(2) << mm.count() << "::"
         << std::setw(2) << ss.count() << "::"
         << std::setw(3) << msec.count() << endl;

    /*
     *  sleep_for(), sleep_until()用以停滞线程
     *  try_lock_for(), try_lock_until()用以等待一个mutex时指定最大时间段
     *  wait_for(), wait_until()用以在等待某条件成立或等待一个future时指定最大时间段
     *  所有的..._for()结束停止都会用到一个dration
     *  所有的...until()的函数都会用到一个timepoint
    */
}

}