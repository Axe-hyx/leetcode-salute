/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
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
  bool search(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[r] == nums[mid]) {
        --r;
        continue;
      }
      if (nums[mid] < target) {
        if (nums[r] >= nums[mid] && nums[r] < target) { // mid 和 r 在一个区间
          r = mid - 1;
        } else
          l = mid + 1;
      } else if (nums[mid] > target) {
        if (nums[l] <= nums[mid] && nums[l] > target) { // mid 和 l 在一个区间
          l = mid + 1;
        } else
          r = mid - 1;
      } else {
          return true;
      }
    }
    if (r < 0)
      return false;
    return nums[r] == target ? true : false;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    vector<int> nums{1, 3};
    help(sol.search(nums, 1));
  }
  {
    vector<int> nums{1, 0, 1, 1, 1};
    help(sol.search(nums, 0));
  }
  {
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    help(sol.search(nums, 6));
  }
  return 0;
}
// @lc code=end
