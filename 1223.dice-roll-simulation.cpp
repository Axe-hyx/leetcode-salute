/*
 * @lc app=leetcode id=1223 lang=cpp
 *
 * [1223] Dice Roll Simulation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int ans = 0;
        // Time Complexity: O(6 ^ n)
        // Space Complexity:
        // dp[left][len][prev]
        void dfs(int left, vector<int> &rollMax, int len, int prev){
            if(left<=0){
                ++ans;
                return;
            }
            for(int i = 0; i<6; ++i){
                if(i == prev && len == rollMax[i]) continue;
                dfs(left-1, rollMax, i==prev ? len + 1:1 , i);
            }


        }


        int dp(int n, vector<int> &rollMax){
            // dp[i][j] combination to pos i, last j
            long dp[n+1][6];
            long sum[n+1];
            memset(dp, 0, sizeof(long) * 6 *(n+1));
            memset(sum, 0, sizeof(long) *  (n+1));

            sum[0] = 1;
            for(int i = 1; i <= n; ++i){
                for(int j = 0; j < 6; ++j){
                    for(int k = 1; k<=rollMax[j]&&i-k>=0; ++k){
                        // dp[i][not j] = sum[i] - dp[i][j]
                        dp[i][j] = (dp[i][j] + sum[i-k] - dp[i-k][j] ) % (int) (1e9 + 7);
                    }
                    sum[i] += dp[i][j] % (int) (1e9+7);
                }
            }
            return sum[n]% (int) (1e9+7);
        }
        int dieSimulator(int n, vector<int>& rollMax) { 
            //ans = 0;
            //dfs(n, rollMax, 0, -1);

            return dp(n, rollMax);
        }
};
int main(){
    Solution sol;
    vector<int> roll = {1, 1, 2, 2, 2, 3};
    cout<<sol.dieSimulator(2, roll)<<endl;
    vector<int> roll1 = {1, 1, 1, 1, 1, 1};
    cout<<sol.dieSimulator(2, roll1)<<endl;
    vector<int> roll2 = {1, 1, 1, 2, 2, 3};
    cout<<sol.dieSimulator(3, roll2)<<endl;
    vector<int> roll3 = {8, 5, 10, 8, 7, 2};
    cout<<sol.dieSimulator(20, roll3)<<endl;
    return 0;
}
// @lc code=end

