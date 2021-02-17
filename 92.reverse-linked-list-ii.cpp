/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
/**
 * Definition for singly-linked list.
 *
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 */
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
      // coner case : [] [3] 1 1 [3, 5] 1 2
    ListNode *s, *t;
    ListNode *tmp = new ListNode();
    tmp->next = head;
    ListNode *p = tmp, *q = nullptr;

    n = n - m + 1;
    while (--m) {
      p = p->next;
    }
    s = p->next;
    ListNode *prev = p, *cur = s;
    t = s;
    while (n-- != 0) {
      q = cur->next;
      {
        cur->next = prev;
        t = cur;
      }
      prev = cur;
      cur = q;
    }

    p->next = t;
    s->next = q;
    auto ans = tmp->next;
    delete tmp;
    return ans;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  /*
  {
    ListNode *r5 = new ListNode(5);
    ListNode *r4 = new ListNode(4, r5);
    ListNode *r3 = new ListNode(3, r4);
    ListNode *r2 = new ListNode(2, r3);
    ListNode *r1 = new ListNode(1, r2);
    auto h = sol.reverseBetween(r1, 2, 4);
    while (h) {
      cout << h->val << " ";
      h = h->next;
    }
    delete r1;
    delete r2;
    delete r3;
    delete r4;
    delete r5;
    cout << endl;
  }
  {
    ListNode *r1 = new ListNode(5);
    auto h = sol.reverseBetween(r1, 1, 1);
    while (h) {
      cout << h->val << " ";
      h = h->next;
    delete r1;
    cout << endl;
    }
  */
  {
    ListNode *r2 = new ListNode(5);
    ListNode *r1 = new ListNode(3, r2);
    auto h = sol.reverseBetween(r1, 1, 2);
    while (h) {
      cout << h->val << " ";
      h = h->next;
    }
    cout << endl;
    delete r1;
    delete r2;
  }

  return 0;
}
// @lc code=end
