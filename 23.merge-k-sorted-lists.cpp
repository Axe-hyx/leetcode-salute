/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 */
class Solution {
    public:
        ListNode* merge(ListNode* l1, ListNode* l2){
            ListNode *p = new ListNode(0);
            ListNode *ans = p;
            while(l1 && l2){
                if(l1->val <= l2->val){
                    p->next = l1;
                    l1 = l1->next;
                }
                else{
                    p->next = l2;
                    l2 = l2->next;
                }
                p = p->next;
            }
            if(l1){
                p->next = l1;
            }
            else if(l2){
                p->next = l2;
            }
            return ans->next;
        }
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            int k = lists.size();
            if(lists.empty()) return nullptr;
            int step = 1;
            while(step<k){
                for(int i = 0; i<k-step; i+= 2*step){
                    lists[i] = merge(lists[i], lists[i+step]);
                }
                step *=2;
            }
            ListNode *p = lists[0];
            while(p){
                printf("%d ", p->val);
                p = p->next;
            }
            printf("\n");

            return lists[0];
        }       
};
int main(int argc, char **argv){
    Solution sol;
    vector<ListNode*> vec;
    struct ListNode * a3 = new ListNode(5);
    struct ListNode * a2 = new ListNode(4, a3);
    struct ListNode * a1 = new ListNode(1, a2);

    struct ListNode * b3 = new ListNode(4);
    struct ListNode * b2 = new ListNode(3, b3);
    struct ListNode * b1 = new ListNode(1, b2);

    struct ListNode * c2 = new ListNode(6);
    struct ListNode * c1 = new ListNode(2, c2);

    vec.push_back(a1);
    vec.push_back(b1);
    vec.push_back(c1);
    ListNode * ans = sol.mergeKLists(vec);

    while(ans){
        printf("%d ", ans->val);
        ans= ans->next;
    }
    delete a3;
    delete a2;
    delete a1;
    delete b2;
    delete b3;
    delete b1;
    delete c2;
    delete c1;
    return 0;
}


// @lc code=end
