/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    // 核心思想，把 [1, 1, 2] 序列变成 [3, 4, 2] （有序序列），确保相对的顺序，去重
  void backtrack(vector<vector<int>> &ans, vector<bool> &used, vector<int> &cur,
                 const vector<int> &nums, int idx) {
    if (idx == nums.size()) {
        ans.push_back(cur);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i] == true) continue;
        if(i!=0 && nums[i] == nums[i-1] && !used[i-1]) continue;
        used[i] = true;
        cur.push_back(nums[i]);
        backtrack(ans, used, cur, nums, idx + 1);
        cur.pop_back();
        used[i] = false;
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<bool> used (nums.size(), false);
    sort(nums.begin(), nums.end());
    vector<int> cur;
    backtrack(ans, used, cur, nums, 0);
    return ans;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    vector<int> nums{1, 1, 2};
    for (auto vec : sol.permuteUnique(nums)) {
      for (auto v : vec) {
        cout << v << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
// @lc code=end
