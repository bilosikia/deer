#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }
        int firstPoint = 0;
        int secondPoint = nums.size() - 1;
        int midPoint = (firstPoint + secondPoint) / 2;
        while(secondPoint - firstPoint > 3) {
            if(nums[midPoint] == target) {
                return midPoint;
            }
            if(nums[firstPoint] < nums[midPoint - 1] && nums[firstPoint] <= target && nums[midPoint - 1] >= target) {
                secondPoint = midPoint - 1;
                midPoint = (firstPoint + secondPoint) / 2;
            }
            else if(nums[firstPoint] > nums[midPoint - 1] && (nums[firstPoint] <= target || nums[midPoint - 1] >= target)) {
                secondPoint = midPoint - 1;
                midPoint = (firstPoint + secondPoint) / 2;
            }
            else if(nums[midPoint + 1] < nums[secondPoint] && nums[midPoint + 1] <= target && nums[secondPoint] >= target) {
                firstPoint = midPoint + 1;
                midPoint = (firstPoint + secondPoint) / 2;
            }
            else if(nums[midPoint + 1] > nums[secondPoint] && (nums[midPoint + 1] <= target || nums[secondPoint] >= target)) {
                firstPoint = midPoint + 1;
                midPoint = (firstPoint + secondPoint) / 2;
            }
            else {
                return -1;
            }
        }
        for(int i = firstPoint; i <= secondPoint; ++i) {
            if(nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};