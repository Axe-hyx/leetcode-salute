/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
  unordered_map<string, vector<string>> maps;
  vector<string> Break(string s, unordered_set<string> &wordDict) {
    vector<string> ans;
    if (s.size() == 0) {
      return ans;
    }
    if (maps.find(s) != maps.end()) {
      return maps[s];
    }
    if (wordDict.count(s))
      ans.push_back(s);
    // 分为前后两部分，后半边直接判断，前半部分直接求解
    for (int i = 1; i < s.size(); ++i) {
      string t = s.substr(i);
      if (wordDict.count(t)) {
        vector<string> tmp = Break(s.substr(0, i), wordDict);
        for (int j = 0; j < tmp.size(); ++j) {
          ans.push_back(tmp[j] + " " + t);
        }
      }
    }
    maps[s] = ans;
    return ans;
  }
  vector<string> wordBreak(string s, vector<string> &wordDict) {
      unordered_set<string> sets(wordDict.begin(), wordDict.end());
      return Break(s, sets);
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    string s{"catsanddog"};
    vector<string> str{"cat", "cats", "and", "sand", "dog"};
    for (auto s : sol.wordBreak(s, str)) {
      cout << s << endl;
    }
  }
  {
    string s{"pineapplepenapple"};
    vector<string> str{"apple", "pen", "applepen", "pine", "pineapple"};
    for (auto s : sol.wordBreak(s, str)) {
      cout << s << endl;
    }
  }
  {
    string s{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
             "aaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
             "aaaaaaaaaaaaaaaaaaaaa"};
    vector<string> str{"a",         "aa",        "aaa",     "aaaa",
                       "aaaaa",     "aaaaaa",    "aaaaaaa", "aaaaaaaa",
                       "aaaaaaaaa", "aaaaaaaaaa"};
    for (auto s : sol.wordBreak(s, str)) {
      cout << s << endl;
    }
  }
}
// @lc code=end
