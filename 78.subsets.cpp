/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    void backtrace(const vector<int> nums, int i, vector<int> &arrays, vector<vector<int>> & anss){
        if(i==nums.size()) {
            anss.push_back(arrays);
            return;
        }
        backtrace(nums, i+1, arrays, anss);
        arrays.push_back(nums[i]);
        backtrace(nums, i+1, arrays, anss);
        arrays.pop_back();
        while(( i+1<nums.size() && nums[i+1] == nums[i])){
            backtrace(nums, i+2, arrays, anss);
            arrays.push_back(nums[i]);
            backtrace(nums, i+2, arrays, anss);
            arrays.pop_back();
            ++i;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> arrays;
        arrays.reserve(nums.size());
        backtrace(nums, 0, arrays, ans);
        return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    vector<int> nums {1, 2, 3};
    sol.subsets(nums);
    return 0;
}
// @lc code=end
