/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    void backtrack(vector<int> &num,  int idx, vector<vector<int>> &ans, unordered_set<int> &sets, const vector<int> &nums) {
      if (idx == nums.size()) {
          ans.push_back(num);
          return ;
      }
      for (int i = 0; i < nums.size(); ++i) {
        if (!sets.count(nums[i])) {
            sets.insert(nums[i]);
            num.push_back(nums[i]);
            backtrack(num, idx+1, ans, sets, nums);
            sets.erase(nums[i]);
            num.pop_back();
        }
      }
  }
  vector<vector<int>> permute(vector<int> &nums) {
      vector<vector<int>> ans;
      vector<int> tmp;
      unordered_set<int> set;
      tmp.reserve(nums.size());
      backtrack(tmp, 0, ans, set, nums);
      return ans;
  }

};
int main(int argc, char **argv){
  Solution sol;
  {
    vector<int> nums{1, 2, 3};
    for (auto vec : sol.permute(nums)) {
      printf("[");
      for (auto v : vec) {
        cout << v << " ";
      }
      printf("]\n");
    }
    {
        vector<int> nums{0, 1};
      for (auto vec : sol.permute(nums)) {
        printf("[");
        for (auto v : vec) {
          cout << v << " ";
        }
        printf("]\n");
      }
    }
  }

  return 0;
}
// @lc code=end
