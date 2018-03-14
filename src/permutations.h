#include <vector>
using namespace std;

class Solution {
public:
    void permuteImp(vector<vector<int>> &result, const vector<int>& nums, vector<int> &p) {
        if(p.size() == nums.size()) {
            result.push_back(p);
        }
        else {
            for(int i = 0; i < nums.size(); ++i) {
                if(find(p.begin(), p.end(), nums[i]) == p.end()) {
                    p.push_back(nums[i]);
                    permuteImp(result, nums, p);
                    p.pop_back();
                }
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> p;
        permuteImp(result, nums, p);
        return result;
    }
};