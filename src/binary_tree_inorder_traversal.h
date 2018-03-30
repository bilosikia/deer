/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <stack>

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> r;
        std::stack<TreeNode *> s;
        if(!root) {
            return r;
        }
        s.push(root);
        while(root->left) {
            root = root->left;
            s.push(root);
        }
        while(!s->empty()) {
            auto node = s.top();
            s.pop();
            r.push_back(ndoe->val);
            if(node->right) {
                s.push(node->right);
                node = node->right;
                while(node->left) {
                    node = node->left;
                    s.push(node);
                }
            }
        }
        return r;
    }
};