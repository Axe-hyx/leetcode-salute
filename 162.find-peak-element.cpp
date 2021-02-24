/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
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
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
          int mid = l + (r - l) / 2;
          int mid2 = mid +1;
          // 走向尖顶
          if(nums[mid] < nums[mid2]){
              l = mid2;
          } else {
            r = mid;
          }
        }
        return r;
    }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    vector<int> nums{1, 2, 3, 1};
    help(sol.findPeakElement(nums));
  }
  {
    vector<int> nums{1, 2, 1, 3, 5, 6, 4};
    help(sol.findPeakElement(nums));
  }
  return 0;
}
// @lc code=end
