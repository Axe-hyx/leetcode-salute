/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:

    int getMoneyAmount(int n) {
        int dp[n][n];
        int height[n][n];
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                dp[i][j] = INT_MAX;
            }
            dp[i][i] = 0;
        }
        for(int len = 1; len<n; ++len){
            for(int l = 0; l< n-len; ++l){
                int r = l + len;
                if(len == 1){
                    dp[l][r] = l + 1;
                    height[l][r] = 2;
                }else if(len == 2){
                    dp[l][r] = l + 2;
                    height[l][r] = 2;
                }
                else{
                    for(int k = l+1; k<r; ++k){
                        // 左右两边选择权最大的路径走，因此 min(max())
                        dp[l][r] = min(dp[l][r], max(dp[l][k-1] , dp[k+1][r] )+ k+1);
                    }
                }
            }
        }
        return dp[0][n-1];
        
    }
};
int main(){
    Solution sol;
    std::cout<<sol.getMoneyAmount(1)<<std::endl;
    std::cout<<sol.getMoneyAmount(2)<<std::endl;
    std::cout<<sol.getMoneyAmount(3)<<std::endl;
    std::cout<<sol.getMoneyAmount(4)<<std::endl;
    std::cout<<sol.getMoneyAmount(5)<<std::endl;
    std::cout<<sol.getMoneyAmount(6)<<std::endl;
    std::cout<<sol.getMoneyAmount(7)<<std::endl;
    std::cout<<sol.getMoneyAmount(8)<<std::endl;
    std::cout<<sol.getMoneyAmount(9)<<std::endl;
    std::cout<<sol.getMoneyAmount(10)<<std::endl;
    return 0;
}
// @lc code=end

