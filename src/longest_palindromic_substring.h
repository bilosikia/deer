#pragma once

#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() == 0) {
            return s;
        }
        if(s.length() == 1) {
            return s;
        }
        int maxLength = 0;
        std::string maxPalindrome = "";
        for (int i = 0; i < s.length() - 1; i++) {
            // 以s[i]为中心, 结果是奇数的情况
            for (int j = 0; i - j >= 0 && i + j < s.length(); j++) {
                if (s[i - j] == s[i + j]) {
                    int count = j * 2 + 1;
                    if (count > maxLength) {
                        maxLength = count;
                        maxPalindrome = s.substr(i - j, count);
                    }
                } else {
                    break;
                }
            }
            // s[i]为中间两个的左边那个的情况，偶数情况
            for (int j = 0; i - j >= 0 && i + j + 1 < s.length(); j++) {
                int left = i - j;
                int right = i + j + 1;
                if (s[left] == s[right]) {
                    int count = j * 2 + 2;
                    if (count > maxLength) {
                        maxLength = count;
                        maxPalindrome = s.substr(left, count);
                    }
                } else {
                    break;
                }
            }
        }

        if (maxPalindrome == "") {
            return "" + s[0];
        }
        return maxPalindrome;
    }
};