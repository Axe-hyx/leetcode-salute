/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "helper.h"
#endif
// Time Complexity: O()
// Space Complexity: O()
/**
 * Definition for singly-linked list.
 * 
 */

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {

            auto cmp = [](ListNode*a, ListNode* b){return a->val > b->val;};
            priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> queue(cmp);
            bool has = false;
            ListNode* p = new ListNode();
            ListNode* head = p;
            for(int i = 0; i<lists.size();++i){
                if(lists[i])
                    queue.push(lists[i]);
            }
            while(!queue.empty()){
                ListNode* t = queue.top();
                queue.pop();
                if(t){
                    if(t->next)
                        queue.push(t->next);
                    p->next = t;
                    p = p->next;
                }

            }
            return head->next;

        }           
};
int main(int argc, char **argv){
    Solution sol;
    {
        ListNode* p1 = new ListNode(5);
        ListNode* p2 = new ListNode(4, p1);
        ListNode* p3 = new ListNode(1, p2);

        ListNode* t1 = new ListNode(4);
        ListNode* t2 = new ListNode(3, t1);
        ListNode* t3 = new ListNode(1, t2);

        ListNode* r1 = new ListNode(6);
        ListNode* r2 = new ListNode(2, r1);
        vector<ListNode*> lists = {p3, t3, r2};
        ListNode* t;
        t = sol.mergeKLists(lists);
        while(t){
            cout<<t->val<<endl;
            t=t->next;
        }
    }
    return 0;
}
// @lc code=end
