/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            int dp[n][2][3];
            memset(dp, -1, sizeof(int) * n * 2 * 3);
            for(int i = 0; i<n;++i){
                for(int j = 0; j<2; ++j){
                    for(int k = 0; k<3; ++k){
                        dp[i][j][k] = INT_MIN;
                    }
                }
            }
            dp[0][0][1] = -prices[0];
            dp[0][1][0] = 0;
            for(int i = 1; i<n;++i){
                dp[i][0][1] = -prices[i];
                // 保证在prices[0, ..., i-1]都不买入的情况下， dp[i][0][1]=-prices[i]
                // dp[i][0][1] 依赖于 dp[i-1][1][0]
                dp[i][1][0] = 0;
                for(int k = 1; k<3; ++k){
                    if(dp[i-1][1][k-1]!=INT_MIN) // 保证k-1项存在
                        dp[i][0][k] = max(dp[i-1][0][k], dp[i-1][1][k-1] - prices[i]); //buy
                    if(dp[i-1][0][k] !=INT_MIN)
                        dp[i][1][k] = max(dp[i-1][1][k], dp[i-1][0][k] + prices[i]);//sell
                }
            }
            int ans = max(dp[n-1][1][2] ,dp[n-1][1][1]);
            return ans > 0 ? ans : 0;
        }
};
int main(){
    Solution sol;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<sol.maxProfit(prices)<<endl;
    vector<int> prices1 = {1,2,3,4,5};
    cout<<sol.maxProfit(prices1)<<endl;
    vector<int> prices2 = {7,6,4,3,1};
    cout<<sol.maxProfit(prices2)<<endl;
    vector<int> prices3 = {1};
    cout<<sol.maxProfit(prices3)<<endl;
    return 0;
}
// @lc code=end

