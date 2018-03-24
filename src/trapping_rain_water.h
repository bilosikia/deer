#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int trap(std::vector<int>& height) {
        std::vector<std::pair<int, int>> v;
        for(int i = 0; i < height.size(); ++i) {
            v.push_back({height[i], i});
        }
        std::sort(v.begin(), v.end(), [](const std::pair<int, int> &first, const std::pair<int, int> &second) {
            if(first.first > second.first) {
                return true;
            }
            return false;
        });

        if(height.size() < 2) {
            return 0;
        }

        // for(auto i : v) {
        //     std::cout << "(" << i.first << i.second << ")" << " ";
        // }
        // std::cout << std::endl;

        int trapCount = 0;
        int pointA = 0, pointB = 1;
        if(v[pointA].second > v[pointB].second) {
            std::swap(pointA, pointB);
        }                                                                                                                                                                                                                 
        bool *flag = new bool[height.size()];
        memset(flag, 0, sizeof(bool) * height.size());

        auto calculate = [&v, &trapCount, &flag, &height](int pointA, int pointB) {
            // std::cout << v[pointA].second << ":" << v[pointB].second << std::endl;
            int usableHeight = v[pointA].first <= v[pointB].first ? v[pointA].first : v[pointB].first;
            for(int i = v[pointA].second; i <= v[pointB].second; ++i) {
                trapCount += height[i] < usableHeight ? usableHeight - height[i] : 0;
                flag[i] = true;
            }
        };

        calculate(pointA, pointB);

        for(int i = 2; i < v.size(); ++i) {
            if(flag[v[i].second] == true) {
                continue;
            }
            if(v[i].second < v[pointA].second) {
                calculate(i, pointA);
                pointA = i;
            }
            else {
                calculate(pointB, i);
                pointB = i;
            }
        }
        delete [] flag;
        return trapCount;
    }
};