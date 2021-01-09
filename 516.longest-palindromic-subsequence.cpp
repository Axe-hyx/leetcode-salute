/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(int) * n * n);
        for(int i = 0; i<n; ++i){
            dp[i][i] = 1;
        }
        for(int l = 1; l<n; ++l){
            for(int i = 0; i < n - l; ++i){
                int j = i + l;
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
int main(){
    Solution sol;
    string s = "bbbab";
    std::cout<<sol.longestPalindromeSubseq(s)<<std::endl;
    string s2 = "cbbd";
    std::cout<<sol.longestPalindromeSubseq(s2)<<std::endl;

    return 0;
}
// @lc code=end

