/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
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
        if(n==0) return 0;
        int dp[n][2];
        memset(dp, 0, sizeof(int) * n * 2);
        dp[0][0] = -prices[0], dp[0][1] = 0;
        for(int i =1; i<n; ++i){
            dp[i][0] = max(dp[i-1][0], i>2?  dp[i-2][1] - prices[i] : -prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
        }
        return dp[n-1][1];
    }
};
int main(int argc, char *argv[]){
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout<<sol.maxProfit(prices)<<endl;
    vector<int> prices1 = {1, 2, 4};
    cout<<sol.maxProfit(prices1)<<endl;
    return 0;
}
// @lc code=end

