#pragma once

#include <string>
#include <cmath>

class Solution {
public:
    int reverse(int x) {
        bool sign = x > 0;
        int abv = std::abs(x);
        std::string s = std::to_string(abv);
        std::string v = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            v = v + s[i];
        }
        int result = 0;
        try {
            result = sign ? std::stoi(v) : -std::stoi(v);
        } catch (std::exception err) {
            return 0;
        }

        return result;
    }
};