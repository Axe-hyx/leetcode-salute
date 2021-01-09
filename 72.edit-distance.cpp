/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        int dp[n+1][m+1];
        for(int i = 0; i<=n; ++i){
            dp[i][0] = i;
        }
        for(int i = 0; i<=m; ++i){
            dp[0][i] = i;
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                }
            }
        }
        return dp[n][m];
    }
};
int main(){
    Solution sol;
    string s1 = "horse", t1 = "ros";
    std::cout<<sol.minDistance(s1, t1)<<std::endl;
    string s2 = "intention", t2 = "execution";
    std::cout<<sol.minDistance(s2, t2)<<std::endl;
    return 0;
}
// @lc code=end

