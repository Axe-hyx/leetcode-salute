/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp = new ListNode;
        tmp->next = head;
        ListNode * f = tmp;
        ListNode * s = tmp;
        while(f && f->next){
            s = f->next;
            f = f->next->next;
            if(!f) break;
            swap(f->val, s->val);
        }
        return head;
    }
};
int main(int argc, char **argv){
    Solution sol;
    sol.swapPairs(nullptr);
    return 0;
}
// @lc code=end
