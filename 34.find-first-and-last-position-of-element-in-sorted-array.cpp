/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
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
  vector<int> searchRange(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    if(!n) return {-1, -1};
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    //0\1 , [5, 7, 7]\6
    if (nums[r] != target)
      return {-1, -1};
    int ll = r, rr = n - 1;
    while (ll < rr) {
        // [3,3]\n3, [3,5]\n, 当有两个元素的时候，需要比较后一个元素，因此mid后移一位
      int mid = ll + (rr - ll + 1) / 2;
      if (nums[mid] < target) {
        ll = mid + 1;
      } else if (nums[mid] > target){
        rr = mid - 1;
      }else
          ll = mid;
    }
    return {r, rr};
  }
};
int main(int argc, char **argv) {
  Solution sol;
  /*
  {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    help(sol.searchRange(nums, 8));
  }
  {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    help(sol.searchRange(nums, 6));
  }
  {
    vector<int> nums{};
    help(sol.searchRange(nums, 0));
  }
  {
      vector<int> nums{1, 3};
    help(sol.searchRange(nums, 1));
  }
  {
    vector<int> nums{3};
    help(sol.searchRange(nums, 1));
  }
  {
      vector<int> nums{2,2};
    help(sol.searchRange(nums, 2));
  }
  */
  {
    vector<int> nums{1, 2, 3, 3, 3, 3, 4, 5, 9};
    help(sol.searchRange(nums, 3));
  }
  return 0;
}
// @lc code=end
