/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
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
  int maxCoins(vector<int> &nums) {
      int n= nums.size() + 2;
      vector<int> pms(nums.size()+2);

      for(int i = 0 ;i<nums.size(); ++i){
          pms[i+1] = nums[i];
      }
      pms[n-1] = 1, pms[0] = 1;
      vector<vector<int>> dp(n, vector<int>(n, 0));
      for (int k = 2; k < n; ++k) {
        for (int left = 0; left < n - k; ++left) {
            int right = left + k;
            for (int tar = left + 1; tar < right; ++tar) {
                dp[left][right] = max(dp[left][right], pms[left] * pms[right] * pms[tar] + dp[left][tar] + dp[tar][right]);
            }
        }
      }
      return dp[0][n-1];
    }
  };
  int main(int argc, char **argv) {
    Solution sol;
    {
      vector<int> nums{3};
      cout << sol.maxCoins(nums) << endl;
    }
    {
      vector<int> nums{3, 1, 5};
      cout << sol.maxCoins(nums) << endl;
    }
    {
      vector<int> nums{3, 1, 5, 8};
      cout << sol.maxCoins(nums) << endl;
    }
    return 0;
  }
  // @lc code=end
