#pragma once
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max = 0;
        int l = 0;
        int r = height.size() - 1;
        while(l < r) {
            max = std::max(max, (r - l) * std::min(height[r], height[l]));
            if(height[l] <= height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max;
    }
};