/*
 * @lc app=leetcode id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
/**
 * Definition for a binary tree node.
 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 */
class Solution {
    public:
        TreeNode* removeLeafNodes(TreeNode* root, int target) {
            stack <TreeNode*> sta;
            TreeNode *prev = nullptr;
            TreeNode *p = root;
            while(!sta.empty() || p){
                while(p){
                    sta.push(p);
                    p = p->left;
                }
                p = sta.top();
                if(p->right == nullptr || p->right == prev){
                    printf("%d ", p->val);
                    //visit
                    if(p->left && p->left->val ==target && !p->left->left && !p->left->right){
                        p->left = nullptr;
                    }
                    if(p->right && p->right->val == target && !p->right->left && !p->right->right){
                        p->right = nullptr;
                    }
                    prev = p;
                    sta.pop();
                    p = nullptr;
                }else{
                    p = p->right;
                }
            }
            if(root && root->val == target && !root->left && !root->right){
                return nullptr;
            }
            return root;
        }
};
int main(int argc, char **argv){
    Solution sol;
    sol.
        return 0;
}
// @lc code=end
