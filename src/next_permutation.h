#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 1) {
            return;
        }
        auto ite = nums.end() - 1;
        for(; ite > nums.begin(); --ite) {
            if(*ite > *(ite - 1)) {
                break;
            }
        }
        if(ite == nums.begin()) {
            reverse(nums.begin(), nums.end());
        }
        else {
            auto swapValue = ite - 1;
            for(ite = nums.end() - 1; *ite <= *swapValue; --ite) {
            }
            swap(*swapValue, *ite);
            reverse(swapValue + 1, nums.end());
        }      
    }
};