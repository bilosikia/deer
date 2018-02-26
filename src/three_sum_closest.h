#pragma once

#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<int> v;
        int l = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                v[l++] = nums[i] + nums[j];
            }
        }
         std::lower_bound(v.begin(), v.end(), target);
    }
};