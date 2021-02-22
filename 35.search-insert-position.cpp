/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "helper.h"
#endif
// Time Complexity: O()
// Space Complexity: O()
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0, r = n-1;
        while (l < r) {
            int mid = l + (r-l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid;
            }else r = mid;
        }
        if(target > nums[r]) return r + 1;
        return r;
    }
};
int main(int argc, char **argv){
    Solution sol;
    {
        vector<int> n {1,3,5,6};
        help(sol.searchInsert(n, 5));
    }
    {
      vector<int> n{1, 3, 5, 6};
      help(sol.searchInsert(n, 2));
    }
    {
      vector<int> n{1, 3, 5, 6};
      help(sol.searchInsert(n, 7));
    }
    {
      vector<int> n{1, 3, 5, 6};
      help(sol.searchInsert(n, 0));
    }
    {
      vector<int> n{1};
      help(sol.searchInsert(n, 0));
    }
    return 0;
}
// @lc code=end
