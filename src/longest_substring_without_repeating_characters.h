#pragma once
#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if(s.empty()) {
            return 0;
        }
        if(s.length() == 1) {
            return 1;
        }
        int maxLength = 1;
        int pre = 0;
        for(auto i = 1; i < s.length(); i++) {
            auto  subStr = s.substr(pre, i - pre);
            auto index = subStr.find(s[i]);
            if(index != std::string::npos) {
                pre = pre + index + 1;
            } else {
                if(i - pre + 1 > maxLength) {
                    maxLength = i - pre + 1;
                }
            }
        }
        return  maxLength;
    }
};