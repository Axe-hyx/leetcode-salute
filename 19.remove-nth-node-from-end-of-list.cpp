/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
/**
 * Definition for singly-linked list.
 * ;
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
      if(!head) return nullptr;
      ListNode* tmp = new ListNode();
      tmp->next = head;
      ListNode *prev = tmp, *p = head;
      while (--n) {
          p = p->next;
      }
      while (p->next) {
        prev = prev->next;
        p = p->next;
      }
      if (prev->next) {
          prev->next = prev->next->next;
      }
      auto ans = tmp->next;
      delete tmp;
      return ans;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    unique_ptr<ListNode> r5(new ListNode(5));
    unique_ptr<ListNode> r4(new ListNode(4, r5.get()));
    unique_ptr<ListNode> r3(new ListNode(3, r4.get()));
    unique_ptr<ListNode> r2(new ListNode(2, r3.get()));
    unique_ptr<ListNode> r1(new ListNode(1, r2.get()));
    auto h = sol.removeNthFromEnd(r1.get(), 2);
    while (h) {
      cout << h->val << " ";
      h = h->next;
    }
    cout << endl;
  }
  {
    unique_ptr<ListNode> r1(new ListNode(1));
    auto h = sol.removeNthFromEnd(r1.get(), 1);
    while (h) {
      cout << h->val << " ";
      h = h->next;
    }
    cout << endl;
  }
  {
    unique_ptr<ListNode> r2(new ListNode(2));
    unique_ptr<ListNode> r1(new ListNode(1, r2.get()));
    auto h = sol.removeNthFromEnd(r1.get(), 1);
    while (h) {
      cout << h->val << " ";
      h = h->next;
    }
    cout << endl;
  }

  return 0;
}
// @lc code=end
