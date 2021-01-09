/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
    public:
        int combinationSum4(vector<int>& nums, int target) {
            return 0;
            int mi = INT_MAX;
            if(nums.size()==0) return 0;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] <= target){
                    mi = min(mi, nums[i]);
                }
            }
            if(mi > target) return 0;

            //无关有符号无符号，其实都会溢出，先判断解可行与否
            unsigned long long dp[target+1];
            memset(dp, 0, sizeof(unsigned long long) * (target + 1));
            // loop time
            dp[0] = 1;
            for(int al= 1; al<=target; ++al){
                for(int i = 0; i<nums.size();++i){
                    if(al>=nums[i] && dp[al-nums[i]] !=0){
                       dp[al] += dp[al-nums[i]];
                    }
                }
            }
            return dp[target];
        }
};
int main(){
    Solution sol;
    vector<int> nm = {1,2,3};
    cout<<sol.combinationSum4(nm, 4)<<endl;
    vector<int> nm1 = {3,33,333};
    cout<<sol.combinationSum4(nm1, 1000)<<endl;
    vector<int> nm2 = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    cout<<sol.combinationSum4(nm2, 10)<<endl;
    vector<int> nm3 = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    cout<<sol.combinationSum4(nm2, 35)<<endl;
    return 0;
}
// @lc code=end

