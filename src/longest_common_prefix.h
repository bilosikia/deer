#pragma once

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        string lcp = strs[0];
        int index = 1;
        while (index < strs.size()) {
            auto s = strs[index];
            int x = 0;
            while (x < lcp.length() && x < s.length() && lcp[x] == s[x]) {
                x++;
            }
            lcp = lcp.substr(0, x);
            index++;
        }
        return lcp;
    }
};