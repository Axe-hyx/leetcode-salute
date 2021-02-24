/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
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
protected:
  void merge(vector<int> &nums, int first, int last, vector<int> &ans,
             vector<int> &indices) {
    int n = last - first;
    if (n > 1) {
      int mid = first + (last - first) / 2;
      merge(nums, first, mid, ans, indices);
      merge(nums, mid, last, ans, indices);

      //WA: 初始化用reserve要配合push_back，其实没有实际分配内存，只是capacity变大
      // 要用resize 或者 () 初始化个数
      vector<int> tmp;
      tmp.resize(n);
      int l = first, r = mid;
      int cnt = 0, right = 0;
      while ((l < mid) || (r < last)) {
        if ((r == last) ||
            (l < mid) && nums[indices[l]] <= nums[indices[r]]) { // left out
          ans[indices[l]] += right;
          tmp[cnt] = indices[l++];
        } else { // right out
          right++;
          tmp[cnt] = indices[r++];
        }
        cnt++;
      }
      move(tmp.begin(), tmp.end(), indices.begin() + first);
    }
  }

public:
  vector<int> countSmaller(vector<int> &nums) {
      vector<int> ans(nums.size(), 0), indices(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      indices[i] = i;
    }
    merge(nums, 0, nums.size(), ans, indices);

    return ans;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  /*
  {
    vector<int> nums = {5, 2, 6, 1};
    help(sol.countSmaller(nums));
  }
  {
    vector<int> nums = {};
    help(sol.countSmaller(nums));
  }
  {
    vector<int> nums = {1, 9, 7, 8, 5};
    help(sol.countSmaller(nums));
  }
  */
  {
    vector<int> nums = {1, 1, 1, 0};
    help(sol.countSmaller(nums));
  }
  {
    vector<int> nums = {26, 78, 27, 100, 33, 67, 90, 23, 66,  5,
                        38, 7,  35, 23,  52, 22, 83, 51, 98,  69,
                        81, 32, 78, 28,  94, 13, 2,  97, 3,   76,
                        99, 51, 9,  21,  84, 66, 65, 36, 100, 41};
    help(sol.countSmaller(nums));
  }
  return 0;
}
// @lc code=end
