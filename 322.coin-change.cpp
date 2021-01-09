/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       // problem here， 注意边界条件
       int dp[amount + 1];

        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            // sum 位置 放在这里，保证是考虑所有coins后minium
            int sum = INT_MAX;
            for(int j = 0; j<coins.size(); ++j){
                if(i>=coins[j]){
                    // 子问题, 不能直接和dp[i]做min,dp[i]必须保证不影响
                    if(dp[i-coins[j]]!=-1){
                        sum = min(sum, dp[i-coins[j]] + 1);
                    }

                }
            }
            dp[i] = sum ==INT_MAX ? -1 : sum;
        }

        return dp[amount];
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> coins={186,419,83,408};
    cout<<sol.coinChange(coins, 6249)<<endl;

    vector<int> coins1={1,2,5};
    cout<<sol.coinChange(coins1, 11)<<endl;

    vector<int> coins2={2};
    cout<<sol.coinChange(coins2,3)<<endl;
    return 0;
}
