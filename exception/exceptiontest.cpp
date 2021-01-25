#include "exceptiontest.h"
namespace ExceptNameSpace{

void exceptTest(){
    auto foo = [](double n){
        try{
            if(n < 0) throw n;
            cout << sqrt(n) << endl;
        }catch(double n){
            cout << n << "不能开根号" << endl;
        }
    };
    auto foo2 = [](int n){
        try{
            if(n > 100)
                throw out_of_range("Error");
            cout << n << endl;
        }catch(const out_of_range e){
            cout << e.what() << endl;
        }
    };
    foo(2);
    foo(-2);
    foo(9);
    foo2(99);
    foo2(111);  
}


}
