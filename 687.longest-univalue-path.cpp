/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include "helper.h"
#endif
// Time Complexity: O()
// Space Complexity: O()
/**
 * Definition for a binary tree node.
 * 
 */
class Solution {
    public:
        int maxlen;
        //depth
        int depth(TreeNode* root){
            if(!root) return 0;
            int l,  r;
            if(root->left && root->left->val == root->val){
                l = depth(root->left);
            }else{
                depth(root->left);
                l = 0;
            }
            if(root->right && root->right->val == root->val){
                r = depth(root->right);
            }else{
                depth(root->right);
                r = 0;
            }
            maxlen = max(maxlen, l + r + 1);
            return max(l, r) + 1;
        }
        int longestUnivaluePath(TreeNode* root) {
            if(!root) return 0;
            maxlen = 0;
            depth(root);
            return maxlen - 1;
        }
};
int main(int argc, char **argv){
    Solution sol;

    {
        TreeNode* r = new TreeNode (1);
        sol.longestUnivaluePath(r);
        cout<<sol.maxlen-1<<endl;
    } 
    { // 2
        TreeNode* r = new TreeNode (5);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(1);
        r->left->right = new TreeNode(1);
        r->right = new TreeNode(5);
        r->right->right = new TreeNode(5);
        Solution sol;
        sol.longestUnivaluePath(r);
        cout<<sol.maxlen-1<<endl;
    }
    { // 2
        TreeNode* r = new TreeNode (1);
        r->left = new TreeNode(4);
        r->left->left = new TreeNode(4);
        r->left->right = new TreeNode(4);
        r->right = new TreeNode(5);
        r->right->left = new TreeNode(5);
        Solution sol;
        sol.longestUnivaluePath(r);
        cout<<sol.maxlen-1<<endl;
    }
    {
        TreeNode* r = new TreeNode (1);
        r->left = new TreeNode(2);
        sol.longestUnivaluePath(r);
        cout<<sol.maxlen-1<<endl;
    }
    {
        TreeNode* r = new TreeNode (1);
        r->right = new TreeNode(1);
        r->right->left = new TreeNode(1);
        r->right->left->left = new TreeNode(1);
        r->right->left->right = new TreeNode(1);
        r->right->right = new TreeNode(1);
        r->right->right->left = new TreeNode(1);
        sol.longestUnivaluePath(r);
        cout<<sol.maxlen-1<<endl;
    }


    return 0;
}
// @lc code=end
