/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
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
    vector<int> diffWaysToCompute(string input) {
        int n = input.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
          if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
            auto lans = diffWaysToCompute(input.substr(0, i)),
                 rans = diffWaysToCompute(input.substr(i + 1, n - (i + 1)));
            for (auto l : lans) {
              for (auto r : rans) {
                if (input[i] == '+') {
                  ans.push_back(l + r);
                } else if (input[i] == '-') {
                  ans.push_back(l - r);
                } else
                  ans.push_back(l * r);
              }
            }
          }
        }
        if (ans.empty()) {
          return {stoi(input)};
        }
        return ans;
    }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    string input{"2-1-1"};
    help(sol.diffWaysToCompute(input));
  }
  {
    string input{"2*3-4*5"};
    help(sol.diffWaysToCompute(input));
  }
  return 0;
}
// @lc code=end
