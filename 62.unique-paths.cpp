/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(int) *(m+1) *(n+1));
        for(int i = 1; i<=n; ++i){
            dp[1][i] = 1;
        }
        for(int i = 2; i<=m; ++i){
            for(int k = 1; k<=n; ++k){
                dp[i][k] = dp[i-1][k] + dp[i][k-1];
            }
        }
        return dp[m][n];
    }
};
int main(){
    Solution sol;
    cout<<sol.uniquePaths(3, 2);
    cout<<sol.uniquePaths(7 , 3);
    return 0;
}
// @lc code=end

