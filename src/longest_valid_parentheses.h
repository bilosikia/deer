#include <string>
#include <stack>
#include <pair>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2) {
            return 0;
        }
        stack<int> que;
        vector<pair<int, int>> record;
        int maxLen = 0;
        for(int ite = s.size() - 1; ite >= 0; --ite) {
            if(s[ite] == ')') {
                que.push(ite);
            }
            else {
                if(que.empty()) {
                    continue;
                }
                else {
                    int endPoint = que.top();
                    int validLen = endPoint - ite + 1;
                    for(auto i : record) {
                        if(i.first == endPoint + 1) {
                            validLen = validLen + i.second;
                            break;
                        }
                    }
                    maxLen = max(maxLen, validLen);
                    que.pop();
                    record.push_back(pair<int, int>(ite, validLen));
                }
            }
        }
        return maxLen;
    }
};