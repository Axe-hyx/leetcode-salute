/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        TreeNode* p = root, *parent;

        while(p){
            if(val < p->val){
                parent = p;
                p = p->left;
            }
            else if(val > p->val){
                parent = p;
                p = p->right;
            }
        }
        if(val < parent->val){
            parent->left = new TreeNode(val);
        }else if(val > parent->val){
            parent->right = new TreeNode(val);
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
