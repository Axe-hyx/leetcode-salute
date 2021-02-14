/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    void combine(int idx, int n, int k, vector<bool> &has, vector<vector<int>> &ans) {
    if (k == 0) {
        vector<int> tmp;
        for (int i = 0; i < has.size(); ++i) {
          if (has[i])
            tmp.push_back(i + 1);
        }
        ans.push_back(tmp);
        return;
    }
    for (int i = idx; i < n; ++i) {
      if (!has[i]) {
        has[i] = true;
        combine(i+1, n, k - 1, has, ans);
        has[i] = false;
      }
    }
    }
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> ans;
      vector<bool> has(n, false);
      combine(0, n, k, has, ans);
      return ans;
    }
};
int main(int argc, char **argv) {
  Solution sol;

  {
    int n = 4, k = 2;
    auto ans = sol.combine(n, k);
    for (auto vec : ans) {
      for (auto v : vec) {
        cout << v << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
// @lc code=end
