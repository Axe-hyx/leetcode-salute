/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
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
        int l = 0, r = n -1;
        while (l < r) {
          if (nums[l] > nums[r]) {
              int mid = l + (r- l ) /2;
              if(nums[mid] >= nums[l])
                  l = mid + 1;
              else r = mid;
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
    vector<int> nums{3, 4, 5, 1, 2};
    help(sol.findMin(nums));
  }
  {
      vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    help(sol.findMin(nums));
  }
  {
      vector<int> nums{1, 2, 3, 4};
    help(sol.findMin(nums));
  }
  return 0;
}
// @lc code=end
