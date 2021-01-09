/*
 * @lc app=leetcode id=1696 lang=cpp
 *
 * [1696] Jump Game VI
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity
class Solution {
    public:
        int maxResult(vector<int>& nums, int k) {
            deque<int> deq;
            int n = nums.size();
            if(n==0) return 0;
            deq.push_back(0);
            for (int i = 1; i < n ; ++i) {
                while (!deq.empty() && deq.front() < i - k) {
                    deq.pop_front();
                }
                while (!deq.empty() && nums[deq.front()] < nums[deq.back()]) {
                    deq.pop_front();
                }
                deq.push_back(i);
                nums[i] = nums[deq.front()]+ nums[i];
            }
            return nums[n-1];
        }

};
int main() {
    Solution sol;
    vector<int> num = {1, -1, -2, 4, -7, 3};
    cout << sol.maxResult(num, 2) << endl;
    vector<int> num1 = {10, -5, -2, 4, 0, 3};
    cout << sol.maxResult(num1, 3) << endl;
    vector<int> num2 = {1,-5,-20,4,-1,3,-6,-3};
    cout << sol.maxResult(num2, 2) << endl;
    return 0;
}
