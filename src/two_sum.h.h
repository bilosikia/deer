#pragma once

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int,int> searchTree;
        for (int i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            if (searchTree.find(other) != searchTree.end()) {
                std::vector<int> result = { i, searchTree[other] };
                std::sort(result.begin(), result.end());
                return result;
            }
            else{
                searchTree[nums[i]] = i;
            }
        }
        return std::vector<int>();
    }
};