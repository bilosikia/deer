#pragma once

#include <complex>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int y = 1;
        int z = x;
        while (z / 10) {
            z = z / 10;
            y++;
        }

        int p = std::pow(10, y - 1);
        int result = 0;
        int v = 0;
        while (y) {
            int t = std::pow(10, v);
            result +=( (x / p ) % 10 ) * t;
            v++;
            y--;
            p = std::pow(10, y - 1);
        }
        if (result == x) {
            return true;
        }
        return false;
    }
};