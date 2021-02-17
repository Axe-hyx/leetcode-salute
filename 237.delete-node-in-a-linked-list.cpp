/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
/**
 * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 */

class Solution {
public:
  void deleteNode(ListNode *node) {
      ListNode *p = node->next;
      ListNode* prev;
      while (p) {
          node->val = p->val;
          prev = node;
          node = node->next;
          p = p->next;
      }
      prev->next = nullptr;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    ListNode *r1{4};
    sol.deleteNode(r1);
  }
  return 0;
}
// @lc code=end
