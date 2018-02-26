// 不知道怎么解

//#pragma once
//
//#include <algorithm>
//#include <vector>
//#include <match.h>
//
//class Solution {
//public:
//    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
//        if (nums1.size() == 0 && nums2.size() == 0) {
//            return 0;
//        }
//        if (nums1.size() == 0) {
//            return nums2.size() % 2 == 0 ? static_cast<double >(nums2[nums2.size() / 2 - 1] + nums2[nums2.size() / 2]) :
//                   nums2[nums2.size() / 2];
//        }
//        if (nums2.size() == 0) {
//            return nums1.size() % 2 == 0 ? static_cast<double >(nums1[nums1.size() / 2 - 1] + nums1[nums1.size() / 2]) :
//                   nums1[nums1.size() / 2];
//        }
//
//        auto isOdd = [](int x)-> bool {
//            return x % 2;
//        };
//        auto aPosition = nums1.end() - 1;
//        auto bPosition = nums2.end() - 1;
//        auto f = [&nums1, &nums2](std::vector::iterator aPosition, std::vector::iterator bPosition)-> double {
//            if (*aPosition >= *bPosition) {
//                // 用b去划分[nums1.begin(), aPosition]
//                auto aIndex = std::lower_bound(nums1.begin(), aPosition, *bPosition);
//                // 判断一下大于等于*bPosition的个数是否是总数的一半
//                int totalSize = nums1.size() + nums2.size();
//                if(isOdd(nums1.size() + nums2.size())) {
//                    if((nums1.end() - aIndex) + (nums2.end() - bPosition) == totalSize / 2 + 1) {
//                        // 则中间数一定在a中或者就是bPosition
//                        return *bPosition;
//                    } else if ((nums1.end() - aIndex) + (nums2.end() - bPosition) > totalSize / 2 + 1) {
//                      int offset = (nums1.end() - aIndex) + (nums2.end() - bPosition - totalSize;
//                        return *(aIndex + offset);
//                    } else {
//                        // 个数不够，继续递归
//                        return (aPosition = -1, bPosition - 1);
//                    }
//                } else {
//                    if((nums1.end() - aIndex) + (nums2.end() - bPosition) == totalSize / 2 + 1) {
//                        // 则中间数一定在a中或者就是bPosition
//                        return (static_cast<double>(*bPosition + *aPosition)) / 2;
//                    } else if ((nums1.end() - aIndex) + (nums2.end() - bPosition) > totalSize / 2 + 1) {
//                        int offset = (nums1.end() - aIndex) + (nums2.end() - bPosition - totalSize;
//                        return static_cast<double >(aIndex + offset);
//                    } else {
//                        // 个数不够，继续递归
//                        return (aPosition = -1, bPosition - 1);
//                    }
//                }
//            }
//
//            if (2 * (nums1.end() - aPosition) + (nums2.end() - bPosition) >= 2 * (nums1.size() + nums2.size())) {
//                return static_cast<double>(*aPosition + *bPosition) / 2;
//            }
//            bool isABigger = nums1[aPosition] > nums2[bPosition];
//            if (isABigger) {
//                aPosition = std::binary_search(nums1.begin(), aPosition, *bPosition);
//            } else {
//                bPosition = std::binary_search(nums2, bPosition, *aPosition);
//            }
//            f(aPosition, bPosition);
//        };
//        a(nums1.end())
//    }
//};