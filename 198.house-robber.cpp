/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1][2];
        memset(dp, 0, sizeof(int) * (n+1) * 2);
        int ans = 0;
        for(int i = 1; i<=n; ++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i-1];
        }
        ans = max(dp[n][0], dp[n][1]);
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> num = {1, 2, 3, 1};
    cout<<sol.rob(num)<<endl;
    vector<int> num1 = {2, 7, 9, 3, 1};
    cout<<sol.rob(num1)<<endl;
    return 0;
}
// @lc code=end

