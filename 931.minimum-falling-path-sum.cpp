/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        int dp[n][m];
        for(int i = 0; i < m; ++i){
            dp[0][i] = A[0][i]; 
        }
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < m; ++j){
                int mini = INT_MAX;
                for(int k = -1; k<=1; ++k){
                    if(j+k >=0 && j+k <m){
                        mini = min(mini, dp[i-1][j+k]);
                    }
                }
                dp[i][j] = mini + A[i][j];
            }
        }
        int res = INT_MAX;
            for(int j = 0; j<m;++j){
                res = min(dp[n-1][j], res);
            }
        return res;
    }
};
// @lc code=end

int main(){
    vector<vector<int>> A = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution sol;
    cout<<sol.minFallingPathSum(A);
    return 0;
}
