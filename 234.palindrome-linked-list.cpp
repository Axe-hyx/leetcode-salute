/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
        bool isEqual(ListNode* cur, ListNode* &back, bool& end, ListNode* head){
            if(cur == nullptr){
                end = true;
                return true;
            }
            ListNode* backptr;
            bool IsEnd = false;
            bool eq = isEqual(cur->next, backptr, IsEnd, head);
            if(!eq) return false;
            if(IsEnd){
                back = head;
            }else{
                back = backptr->next;
            }
            if(back->val != cur->val)
                return false;
            else return true;
        }
        bool isPalindrome(ListNode* head) {
            ListNode* backptr;
            bool IsEnd = false;
            return isEqual(head, backptr, IsEnd, head);
        }
};
int main(int argc, char **argv){

    Solution sol;
    {
        ListNode* r1 = new ListNode(1);
        ListNode* r2 = new ListNode(2);
        r1->next = r2;
        cout<<sol.isPalindrome(r1)<<endl;

    }
    {
        ListNode* r1 = new ListNode(1);
        ListNode* r2 = new ListNode(2);
        ListNode* r3 = new ListNode(2);
        ListNode* r4 = new ListNode(1);
        r1->next = r2;
        r2->next = r3;
        r3->next = r4;
        cout<<sol.isPalindrome(r1)<<endl;

    }
    return 0;
}

// @lc code=end
