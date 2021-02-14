/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
/**
 * Definition for singly-linked list.
 *  */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            if(!head) return nullptr;
            ListNode *odd = head, *podd = odd;
            ListNode *even = head->next, *peven = even;
            ListNode * he = even;
            while(1){
                if(odd){
                    podd = odd;
                    if(odd->next){ // 是否能向后延伸
                        odd = odd->next->next;
                        podd->next = odd;
                    }else{
                        break;
                    }
                }else{  //是否存在合理的下一个位置
                    break;
                }
                if(even){
                    peven = even;
                    if(even->next){
                        even = even->next->next;
                        peven->next = even;
                    }else{
                        break;
                    }
                }else{
                    break;
                }
            }
            podd->next = he;
            return head;
        }
};
int main(int argc, char **argv){
    Solution sol;
    /*
       {
       ListNode * r1 = new ListNode{1};
       auto t = sol.oddEvenList(r1);
       while(t){
       cout<<t->val<<" ";
       t = t->next;
       }
       cout<<endl;
       }
       return 0;

       {
       ListNode * r2 = new ListNode{2};
       ListNode * r1 = new ListNode{1, r2};
       auto t = sol.oddEvenList(r1);
       while(t){
       cout<<t->val<<" ";
       t = t->next;
       }
       cout<<endl;
       }
       {
       ListNode * r1 = new ListNode{1};
       auto t = sol.oddEvenList(r1);
       while(t){
       cout<<t->val<<" ";
       t = t->next;
       }
       cout<<endl;
       }
       */
    {
        ListNode * r3 = new ListNode{3};
        ListNode * r2 = new ListNode{2, r3};
        ListNode * r1 = new ListNode{1, r2};
        auto t = sol.oddEvenList(r1);
        while(t){
            cout<<t->val<<" ";
            t = t->next;
        }
        cout<<endl;
    }
    return 0;
}
// @lc code=end
