#pragma once

#include <string>
#include <cmath>

class Solution {
public:
    int myAtoi(std::string str) {
        std::string value = "";
        bool isPositive = true;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= '0' && str[i] <= '9') {
               if(i - 1 >= 0 && value == "" && (str[i - 1] == '+' || str[i - 1] == '-')){
                   if(i -2 >= 0 && str[i -2] != ' ') {
                       continue;
                   }
                   if (str[i - 1] == '-') {
                        isPositive = !isPositive;
                    }
                }
                value += str[i];
            } else if (value != "") {
                break;
            }
        }

        int result = 0;
        for (int i = value.length() - 1, j = 0; i >= 0; i--, j++) {
            result += (value[i] - '0') * std::pow(10, j);
        }
        if (isPositive) {
            return result;
        } else {
            return -result;
        }
    }
};
