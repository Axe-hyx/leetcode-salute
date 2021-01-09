/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int dp[n+1][m+1];
        dp[0][0] = 0;
        memset(dp, 0, sizeof(int) * (n+1) * (m+1));
        for(int i = 1; i<=n;++i){
            for(int j = 1; j<=m; ++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};
int main(){
    Solution sol;
    string s1 = "abcde", t1 = "ace";
    std::cout<<sol.longestCommonSubsequence(s1, t1)<<std::endl;
    string s2 = "abc", t2 = "abc";
    std::cout<<sol.longestCommonSubsequence(s2, t2)<<std::endl;
    string s3 = "abc", t3 = "def";
    std::cout<<sol.longestCommonSubsequence(s3, t3)<<std::endl;
    return 0;
}
// @lc code=end

