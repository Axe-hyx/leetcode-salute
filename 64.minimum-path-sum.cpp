/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        int dp [m][n];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i = 1; i < n; ++i){
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }

        for(int i = 1; i<m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<vector<int>> grid= {{1,3,1}, {1,5,1}, {4,2,1}};
    cout<<sol.minPathSum(grid);

}

