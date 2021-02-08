/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
/**
 * Definition for a binary tree node.
 *  */

class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            stack<TreeNode*> order;
            TreeNode *p = root;
            int seq = -INT_MAX;
            bool init = true;
            while(p!=nullptr || !order.empty()){
                if(p !=nullptr){
                    order.push(p);
                    p = p->left;
                    continue;
                }
                if(!order.empty()){
                    p = order.top();
                    order.pop();
                    if(init == true){
                        init = false;
                        seq = p->val;
                    }
                    else{
                        if(seq >= p->val) return false;
                        seq = p->val;
                    }
                }
                p = p->right;
            }
            return true;
        }
        
};

int main(int argc, char **argv){
    Solution sol;
    {
        TreeNode *p = new TreeNode(2);
        TreeNode *p1 = new TreeNode(1);
        TreeNode *p2 = new TreeNode(3);
        p->left = p1;
        p->right = p2;
        cout<<sol.isValidBST(p)<<endl;
    }
    {
        TreeNode *p = new TreeNode(5);
        TreeNode *p1 = new TreeNode(1);
        p->left = p1;
        TreeNode *p2 = new TreeNode(4);
        p->right = p2;
        TreeNode *p3 = new TreeNode(3);
        p2->left = p3;
        TreeNode *p4 = new TreeNode(6);
        p2->right = p4;
        cout<<sol.isValidBST(p)<<endl;
    }
    {
        TreeNode *p = new TreeNode(1);
        TreeNode *p1 = new TreeNode(1);
        p->left = p1;
        cout<<sol.isValidBST(p)<<endl;
    }

    return 0;
}
// @lc code=end
