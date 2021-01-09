/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {    
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size(); 
        int dp[n][m];
        memset(dp, 0, sizeof(int) * (n) * (m));
        for(int i = 0; i<m; ++i){
            if(obstacleGrid[0][i] != 1){
                dp[0][i] = 1;
            }else break;
        }
        for(int i = 0; i<n; ++i){
            if(obstacleGrid[i][0] != 1){
                dp[i][0] = 1;
            }else break;
        }

        for(int i = 1; i<n;++i){
            for(int k = 1; k<m;++k){
                if(obstacleGrid[i][k] != 1){
                    dp[i][k] = (obstacleGrid[i-1][k] == 1 ? 0 : dp[i-1][k]) + 
                        (obstacleGrid[i][k-1] == 1 ? 0 : dp[i][k-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};
int main(){
    Solution sol;
    vector<vector<int>> ob={{0,0,0},{0,1,0},{0,0,0}};
    cout<<sol.uniquePathsWithObstacles(ob)<<endl;
    return 0;
}
// @lc code=end

