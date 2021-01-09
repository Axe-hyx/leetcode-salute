/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dp[n][2];
        memset(dp, 0, sizeof(int) * 2 * n);
        // dp[i][j] 到i 位置最后动作是j，得到的最大利润
        dp[0][0] = -prices[0], dp[0][1] = 0;
        /*
         * 贪心是错误的,fee存在1,3,7,5,10,3:3
        int mp = prices[0];
        int ans = 0;
        for(int i = 1; i<n; ++i){
            if(dp[i-1][1] != 0) mp = prices[i];
            dp[i][0] = -mp;
            if(prices[i] - fee - mp > 0){
                dp[i][1] = prices[i] - fee - mp;
                ans += dp[i][1];
            }else{
                dp[i][1] = 0;
            }
            printf("%d %d\n", dp[i][0], dp[i][1]);
            mp = min(mp, prices[i]);
        }
        */
        dp[0][0] = -prices[0], dp[0][1] = 0;
        for(int i = 1; i<n;++i){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] - prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - fee + prices[i]);
        }
        return dp[n-1][1];
    }
};
int main(){
    Solution sol;
    vector<int> prices =  {1, 3, 2, 8, 4, 9};
    cout<<sol.maxProfit(prices, 2)<<endl;
    vector<int> prices1 =  {1, 3, 7, 5, 10, 3};
    cout<<sol.maxProfit(prices1, 3)<<endl;
    return 0;
}
// @lc code=end

