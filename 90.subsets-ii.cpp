/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
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
        int cnt = 1;
        while(( i+1<nums.size() && nums[i+1] == nums[i])){
            ++cnt;
            ++i;
        }
        backtrace(nums, i+1, arrays, anss);
        for(int j = 0; j<cnt; ++j){
            arrays.push_back(nums[i]);
            backtrace(nums, i+1, arrays, anss);
        }
        for(int j = 0; j<cnt; ++j){
            arrays.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
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
    sol.subsetsWithDup(nums);
    return 0;
}
// @lc code=end
