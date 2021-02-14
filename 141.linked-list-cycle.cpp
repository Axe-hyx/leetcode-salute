/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
       ListNode* fast = head;
       ListNode* slow = head;
       while(fast && fast->next){
           fast = fast->next->nest;
           slow = slow->next;
           if(flat == slow) return false;
       }
       return true;
    }
};
int main(int argc, char **argv){
    Solution sol;
    sol.hasCycle();
    return 0;
}
// @lc code=end
