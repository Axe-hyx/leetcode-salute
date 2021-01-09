/*
 * @lc app=leetcode id=1269 lang=cpp
 *
 * [1269] Number of Ways to Stay in the Same Place After Some Steps
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int numWays(int steps, int arrLen) {
        // 模1e9+7 一定要搭配unsigned int 因为正好是一半，加法也不会溢出
        int len = min(500, arrLen);
        unsigned int dp[steps+1][len];
        memset(dp, 0, sizeof(unsigned int)*len*(steps+1));
        dp[0][0] = 1;

        for(int n = 1; n<=steps; ++n){
            for(int i = 0; i<len; ++i){
                dp[n][i] = (i>0?dp[n-1][i-1] : 0) + dp[n-1][i] + (i<len-1? dp[n-1][i+1] : 0);
                dp[n][i] %= (unsigned int)1e9+7;
            }
        }
        return dp[steps][0];
    }

};
int main(){
    Solution sol;
    sol.numWays(3, 2);
    sol.numWays(2, 4);
    sol.numWays(4, 2);
    sol.numWays(27, 7);
    return 0;
}
// @lc code=end

