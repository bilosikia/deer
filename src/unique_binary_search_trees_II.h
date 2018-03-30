/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 递归
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0) {
            return std::vector<TreeNode *>();
        }
        return generateTree(1, n);
    }

    std::vector<TreeNode *> generateTree(int start, int end) {
        std::vector<TreeNode *> r;
        if(start > end) {
            r.push_back(nullptr);
        }
        else if(start == end) {
            r.push_back(new TreeNode(start));
        }
        else {
            for(int i = start; i <= end; ++i) {
                std::vector<TreeNode *> left = generateTree(start, i - 1);
                std::vector<TreeNode *> right = generateTree(i + 1, end);
                for(auto li : left) {
                    for(auto ri : right) {
                        TreeNode *root = new TreeNode(i);
                        root -> left = li;
                        root -> right = ri;
                        r.push_back(root);
                    }
                }
            }
        }
        return r;
    }
};

// dp
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0) {
            return std::vector<TreeNode *>();
        }

        std::vector<std::vector<std::vector<TreeNode *>>> dp;
        for(int i = 0; i <= n; ++i) {
            dp.push_back(std::vector<std::vector<TreeNode *>>());
            for(int j = 0; j <= n; ++j) {
                dp[i].push_back(std::vector<TreeNode *>());
            }
        }
        generate(dp, n);
        return dp[1 - 1][n - 1];
    }

    void generate(std::vector<std::vector<std::vector<TreeNode *>>> &dp, int n) {
        for(int len = 0; len < n; ++len) {
            for(int i = 1; i + len <= n; ++i) {
                
                for(int j = i; j <= i + len; ++j) {
                    auto lefts = i > j -1 ? std::vector<TreeNode *>{nullptr} : dp[i - 1][j - 1 - 1];
                    auto rights = j + 1 > i + len ? std::vector<TreeNode *>{nullptr} : dp[j + 1 -1][i + len -1];
                    for(auto l : lefts) {
                        for(auto r : rights) {
                            TreeNode *node  = new TreeNode(j);
                            node->left = l;
                            node->right = r;
                            dp[i - 1][i + len - 1].push_back(node);
                        }
                    }
                }
            }
        }
    }
};