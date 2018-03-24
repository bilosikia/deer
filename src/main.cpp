#include <utility>
#include "trapping_rain_water.h"
using namespace std;

int main() {
    Solution s;
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << s.trap(v);
    return 0;
}
