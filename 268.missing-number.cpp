/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
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
    int missingNumber(vector<int>& nums) {
        int Xor = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
          Xor = Xor ^ i ^ nums[i];
        }
        return Xor ^ n;
    }
};
int main(int argc, char **argv){
    Solution sol;
    {
      vector<int> nums{3, 0, 1};
      help(sol.missingNumber(nums));
    }
    {
      vector<int> nums{0, 1};
      help(sol.missingNumber(nums));
    }
    {
        vector<int> nums{6, 9, 4, 2, 3, 5, 7, 0, 1};
      help(sol.missingNumber(nums));
    }
    return 0;
}
// @lc code=end
