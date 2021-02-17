/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        TreeNode *prev = nullptr;
        TreeNode *p = root;
        stack<TreeNode*> sta;
        while(!sta.empty() || p){
            while(p){
                sta.push(p);
                p = p->left;
            }
            p = sta.top();
            if(p->right == nullptr || p->right == prev){
                ans.push_back(p->val);
                sta.pop();
                prev = p;
                p = nullptr;
            }else{
                p = p->right;
            }
        }
        return ans;

    }
};
int main(int argc, char **argv){
    Solution sol;
    sol.
    return 0;
}
// @lc code=end
