/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n =0;
        for(auto s : nums){
            n+=s;
        }
        if(n%2!=0) return false;
        n/=2;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 0; i<nums.size(); ++i){
            vector<int> ndp(n+1, 0);
            for(int j = 0; j<=n; ++j){
                if(dp[j]!=0){
                    ndp[j] = 1;
                    if(j + nums[i] <=n){
                        ndp[j+nums[i]] = 1;
                    }
                }
            }
            dp = ndp;
            for(auto i : dp){
                // cout<<i<<" ";
            }
            // cout<<endl;

        }
        return dp[n] == 1;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    cout<<sol.canPartition(nums)<<endl;
    vector<int> nums1 = {1, 2, 3, 5};
    cout<<sol.canPartition(nums1)<<endl;
    return 0;
}
// @lc code=end

