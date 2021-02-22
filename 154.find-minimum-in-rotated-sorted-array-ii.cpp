/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
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
    int findMin(vector<int>& nums) {
      int n = nums.size();
      int l = 0, r = n - 1;
      while (l < r) {
        if (nums[l] >= nums[r]) {
          int mid = l + (r - l) / 2;
          if (nums[mid] == nums[r]) {
            r--;
            continue;
          }
          if (nums[mid] >= nums[l])
            l = mid + 1;
          else
            r = mid;
        } else {
          return nums[l];
        }
      }
      return nums[r];
    }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    vector<int> nums{1, 3, 5};
    help(sol.findMin(nums));
  }
  {
    vector<int> nums{2, 2, 2, 0, 1};
    help(sol.findMin(nums));
  }
  {
    vector<int> nums{2, 2, 2, 0, 1, 2};
    help(sol.findMin(nums));
  }
  {
      vector<int> nums{10, 1, 10, 10, 10};
    help(sol.findMin(nums));
  }
  return 0;
}
// @lc code=end
