/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n==0 ) return 0;
        int dp[n][2][k+1];
        memset(dp, -1, sizeof(int) * n * 2 * (k+1));
        for(int i = 0; i<n;++i){
            for(int j = 0; j<2; ++j){
                for(int l = 0; l<=k; ++l){
                    dp[i][j][l] = INT_MIN;
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
            for(int l = 1; l<=k; ++l){
                if(dp[i-1][1][l-1]!=INT_MIN) // 保证l-1项存在
                    dp[i][0][l] = max(dp[i-1][0][l], dp[i-1][1][l-1] - prices[i]); //buy
                if(dp[i-1][0][l] !=INT_MIN)
                    dp[i][1][l] = max(dp[i-1][1][l], dp[i-1][0][l] + prices[i]);//sell
            }
        }
        int ans = 0;
        for(int i = 1; i<=k; ++i){
            ans = max(dp[n-1][1][i], ans);
        }
        return ans > 0 ? ans : 0;       
    }
};
int main(){
    Solution sol;
    vector<int> prices = {2, 4, 1};
    cout<<sol.maxProfit(2, prices)<<endl;
    vector<int> prices2= {3,2,6,5,0,3};
    cout<<sol.maxProfit(2, prices2)<<endl;
    vector<int> prices3= {1,3};
    cout<<sol.maxProfit(0, prices3)<<endl;
    return 0;
}
// @lc code=end

