/*
 * @lc app=leetcode id=903 lang=cpp
 *
 * [903] Valid Permutations for DI Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "helper.h"
#endif
// Time Complexity: O()
// Space Complexity: O()

// O^3, O ^ 3
class Solution {
public:
  int numPermsDISequence(string S) {
      int n = S.size();
      int dp[n + 1][n + 1];
      memset(dp, 0, sizeof(int) * (n + 1) * (n + 1));
      for (int j = 0; j <= n; ++j) {
          dp[0][0] =  1;
      }
      int m = (int) (1e9 + 7);
      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
          if (S[i - 1] == 'D') {
            // > j, [j+1, n]
            for (int k = j + 1; k <= i; ++k) {
              dp[i][j] += dp[i - 1][k] % m;
            }
          } else {
            // < j, [0,j-1]
            for (int k = 0; k <= j - 1; ++k) {
              dp[i][j] += dp[i - 1][k] % m;
            }
          }
        }
      }
      cout << "dp"<<endl;
      for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
          cout << dp[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
      int ans = 0;
      for (int i = 0; i <= n; ++i) {
        ans += dp[n][i];
      }
      return ans;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    string s{"DID"};
    help(sol.numPermsDISequence(s));
  }
  return 0;
  {
    string s{"IDDDIIDIIIIIIIIDIDID"};
    help(sol.numPermsDISequence(s));
  }
  return 0;
}
// @lc code=end
