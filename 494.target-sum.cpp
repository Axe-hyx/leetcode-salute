/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int off = 1000;
        if(S > off || S < -off){return 0;}
        int dp [n+1][2001];
        memset(dp, 0 , sizeof(int)*(n+1)*2001);
        dp[0][off] = 1;
        for(int i = 1; i<=n; ++i){
            for(int sum = 0; sum<=2000;++sum){
                int target = sum -off;
                if(dp[i-1][sum]!=0){
                   int l = sum-nums[i-1];
                   int r = sum+nums[i-1];
                   if(l>=0 && l<=2000){
                       dp[i][l] += dp[i-1][sum];
                   }
                   if(r>=0 && r<=2000){
                       dp[i][r] += dp[i-1][sum];
                   }
                }
            }
            
            for(int sum = 0; sum<=2000;++sum){
                if(dp[i][sum] != 0)
                    cout<<sum - off<<":"<<dp[i][sum]<<" ";
            }
            cout<<endl;
        }
        return dp[n][S+off];
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,1,1,1,1};
    cout<<sol.findTargetSumWays(nums, 3)<<endl;

    vector<int> nums1 = {1,2,7,9,981};
    cout<<sol.findTargetSumWays(nums1, 1000000000)<<endl;
    return 0;
}
// @lc code=end

