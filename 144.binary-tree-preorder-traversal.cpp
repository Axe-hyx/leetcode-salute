/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
/**
 * Definition for a binary tree node.
 *
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode()
      : val(0), left(nullptr), right(nullptr){} * TreeNode(int x)
      : val(x),
        left(nullptr),
        right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x),
        left(left), right(right) {}
};
class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
      stack<TreeNode*> st;
      TreeNode * p = root;
      vector<int> ans;
      while (!st.empty() || p) {
        if (p) {
          ans.push_back(p->val);
          if (p->right) {
            st.push(p->right);
          }
          if (p->left) {
            st.push(p->left);
          }
          p = nullptr;
        } else {
          p = st.top();
          st.pop();
        }
      }
      return ans;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    unique_ptr<TreeNode> t3(new TreeNode(3));
    unique_ptr<TreeNode> t2(new TreeNode(2));
    unique_ptr<TreeNode> t1(new TreeNode(1, nullptr, t2.get()));
    sol.preorderTraversal(t1.get());
  }
  return 0;
}
// @lc code=end
