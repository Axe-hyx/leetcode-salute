/*
 * @lc app=leetcode id=932 lang=cpp
 *
 * [932] Beautiful Array
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
    //WA:: cache, 递归，
  unordered_map<int, vector<int>> map;
  vector<int> f(int N) {
    vector<int> ans(0, N);
    if (N != 1) {
      if (map.find(N) != map.end()) {
        return map[N];
      }
      for (auto v : f((N + 1) / 2)) {
        ans.push_back(v * 2 - 1);
      }
      for (auto v : f(N / 2)) {
        ans.push_back(v * 2);
      }
    } else {
      ans.push_back(1);
    }
    map[N] = ans;
    return ans;
  }
  // WA::递推错误
  vector<int> beautifulArray(int N) { return f(N); }
};
int main(int argc, char **argv) {
  Solution sol;
  { help(sol.beautifulArray(1)); }
  { help(sol.beautifulArray(2)); }
  { help(sol.beautifulArray(3)); }
  { help(sol.beautifulArray(4)); }
  { help(sol.beautifulArray(5)); }
  { help(sol.beautifulArray(6)); }
  return 0;
}
// @lc code=end
