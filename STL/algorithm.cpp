#include "container.h"
using std::cout;
using std::endl;

namespace AlgorithmNamespace{

static void simpleAlg()
{
    auto algo1 = [](){
        std::vector<int> coll = {2, 5, 4, 1, 6, 3};
        auto minpos = std::min_element(coll.cbegin(), coll.cend());
        cout << "min: " << *minpos << endl;
        auto maxpos = std::max_element(coll.cbegin(), coll.cend());
        cout << "max: " << *maxpos << endl;

        std::sort(coll.begin(), coll.end());

        auto pos3 = std::find(coll.begin(), coll.end(), 3);

        std::reverse(pos3, coll.end());

        for(auto &elem : coll){
            cout << elem << " ";
        }
        cout << endl;
    };
    algo1();
}

void algorithmTest()
{
    simpleAlg();
}

}