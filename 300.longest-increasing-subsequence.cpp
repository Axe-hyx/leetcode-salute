/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
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
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> dp;
        for (int i = 0; i < n; ++i) {
            //auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            // lower_bound
            int l = 0, r = (int)dp.size();
            while (l < r) {
                int mid = l + (r-l) / 2;
                if (dp[mid] < nums[i]) {
                    l = mid+1;
                } else {
                    r = mid;
                }
            }
            if (r ==dp.size() || dp[r] < nums[i]) {
              dp.push_back(nums[i]);
              ans = std::max(ans, (int)dp.size());
            } else {
              dp[r] = nums[i];
            }
        }
        return ans;
    }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    help(sol.lengthOfLIS(nums));
  }
  {
    vector<int> nums{0, 1, 0, 3, 2, 3};
    help(sol.lengthOfLIS(nums));
  }
  {
    vector<int> nums{7, 7, 7, 7, 7, 7, 7};
    help(sol.lengthOfLIS(nums));
  }
  return 0;
}
// @lc code=end
