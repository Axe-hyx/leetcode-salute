/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "helper.h"
#endif
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n;) {
      if (nums[i] <= 0 || nums[i] > n) { // 区间能放置的元素，[1,n]
        nums[i] = 0;
        ++i;
      } else {
        if (nums[i] == i + 1 ||
            nums[i] == nums[nums[i] - 1]) { //如果元素重复或者已经放到该在的位置
          ++i;
          continue;
        }
        swap(nums[i], nums[nums[i] - 1]); // 按照大小放置
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1)
        return i + 1;
    }
    return n + 1;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    vector<int> nums{3, 4, -1, 1};
    help(sol.firstMissingPositive(nums));
  }
  {
    vector<int> nums{1, 2, 0};
    help(sol.firstMissingPositive(nums));
  }
  {
    vector<int> nums{7, 8, 9, 11, 12};
    help(sol.firstMissingPositive(nums));
  }
  {
    vector<int> nums{1, 1};
    help(sol.firstMissingPositive(nums));
  }
  return 0;
}
// @lc code=end
