/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
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
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    sort(envelopes.begin(), envelopes.end(),
         [](vector<int> &en1, vector<int> en2) {
           if (en1[0] < en2[0])
             return true;
           else if (en1[0] == en2[0])
             return en1[1] > en2[1];
           return false;
         });
    int ans = 0;
    vector<int> dp;
    int n = envelopes.size();
    for (int i = 0; i < n; ++i) {
        int l = 0, r = dp.size();
        while (l < r) {
            int mid = l + (r-l) / 2;
            if (envelopes[dp[mid]][1] < envelopes[i][1]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (r == dp.size() || envelopes[dp[r]][1] < envelopes[i][1]) { // push
          dp.push_back(i);
        } else { // overwrite
            dp[r] = i;
        }
    }
    return dp.size();
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
      vector<vector<int>> nums{{5, 4}, {6, 4}, {6, 7}, {2, 3}}; // 3
    help(sol.maxEnvelopes(nums));
  }
  {
      vector<vector<int>> nums{{30, 50}, {12, 2}, {3, 4}, {12, 15}}; //3
    help(sol.maxEnvelopes(nums));
  }
  {
      vector<vector<int>> nums{{4, 5}, {4, 6}, {6, 7}, {2, 3}, {1, 1}, {1, 1}}; // 4
    help(sol.maxEnvelopes(nums));
  }
  return 0;
}
// @lc code=end
