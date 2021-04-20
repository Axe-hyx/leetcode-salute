/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
/**
 * Definition for singly-linked list.
 * 
 * */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* next = head->next;
        ListNode *prev = head;
        head->next = nullptr;
        while(next){
            ListNode* t = next->next;
            next->next = prev;
            prev = next;
            next = t;
        }
        return prev;
    }
};
int main(int argc, char **argv){
    Solution sol;
    {}
    sol.reverseList(nullptr);
    return 0;
}
// @lc code=end
