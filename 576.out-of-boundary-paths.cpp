/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<unsigned int>> dp (m, vector<unsigned int>(n, 0));
        long long ans = 0;
        dp[i][j] = 1;
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};
        for(int k = 0; k<N; ++k){
            vector<vector<unsigned int>> ndp(m, vector<unsigned int>(n, 0));
            for(int i = 0; i<m; ++i){
                for(int j = 0; j<n; ++j){
                    if(dp[i][j]!=0)
                    {
                        for(int id = 0; id<4; ++id){
                                int x = i + dx[id];
                                int y = j + dy[id];
                                if(x >=0 && x<m && y>=0 && y<n){
                                    ndp[x][y] += dp[i][j];
                                    ndp[x][y] %= (long)1e9+7;
                                }else{
                                    ans += (long)dp[i][j];
                                    ans%= (long)1e9+7;
                                }
                        }
                    }
                }
            }
            dp = ndp;
        }
        return ans;
    }
};
int main(){
    Solution sol;
    cout<<sol.findPaths(2, 2, 2, 0, 0)<<endl;
    cout<<sol.findPaths(1, 3, 3, 0, 1)<<endl;
    cout<<sol.findPaths(8, 50, 23, 5, 26)<<endl;
    return 0;
}
// @lc code=end

