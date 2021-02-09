/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
  vector<vector<char>> maps{{'a', 'b', 'c'}, {'d', 'e', 'f'},
                            {'g', 'h', 'i'}, {'j', 'k', 'l'},
                            {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                            {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.size() == 0)
      return ans;
    if (digits.size() == 1) {
      for (auto c : maps[digits[0] - '2']) {
          ans.push_back(string(1, c));
      }
    } else {
      auto tmp = letterCombinations(digits.substr(1));
      for (auto c : maps[digits[0] - '2']) {
        for (auto s : tmp) {
          ans.push_back(c + s);
        }
      }
    }
    return ans;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    string s{"23"};
    for (auto ans : sol.letterCombinations(s)) {
      cout << ans << endl;
    }
  }
  {
    string s{""};
    for (auto ans : sol.letterCombinations(s)) {
      cout << ans << endl;
    }
  }
  {
    string s{"2"};
    for (auto ans : sol.letterCombinations(s)) {
      cout << ans << endl;
    }
  }

  return 0;
}
// @lc code=end
