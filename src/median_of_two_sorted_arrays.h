#pragma once

#include <algorithm>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int aPosition = nums1.size() - 1;
        int bPosition = nums2.size() - 1;
        bool isABigger = nums1[aPosition] > nums2[bPosition];

        auto f = [&nums1, &nums2](std::vector::iterator aPosition, std::vector::iterator bPosition) {
            if(aPosition == std::vector::end()) {
                
            }

           if(2 * (nums1.end() - aPosition) + (nums2.end() - bPosition) >= 2 * (nums1.size() + nums2.size())) {
               return  static_cast<double>(*aPosition + *bPosition) / 2;
           }
            bool isABigger = nums1[aPosition] > nums2[bPosition];
            if(isABigger) {
               aPosition = std::binary_search(nums1.begin(), aPosition, *bPosition);
            } else {
                bPosition = std::binary_search(nums2, bPosition, *aPosition);
            }
            f(aPosition, bPosition);
        };
    }
};