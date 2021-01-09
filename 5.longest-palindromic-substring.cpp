/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(int) * n * n);
        int maxl = 0, t;
        string ans;
        for(int l = 0; l<n; ++l){
            for(int i = 0; i<n-l; ++i){
                int j = i + l;
                dp[i][j] = s[i] == s[j] && (j-i + 1 < 3 || dp[i+1][j-1]);
                if(dp[i][j] && (j-i + 1)>maxl){
                    maxl = j-i+1;
                    t = i;
                }
            }
        }
        ans = s.substr(t, maxl);
        return ans;

    }
};
int main(){
    Solution sol;
    string s1 = "babad";
    cout<<sol.longestPalindrome(s1)<<endl;
    string s2 = "cbbd";
    cout<<sol.longestPalindrome(s2)<<endl;
    string s3 = "a";
    cout<<sol.longestPalindrome(s3)<<endl;
    string s4 = "ac";
    cout<<sol.longestPalindrome(s4)<<endl;
    return 0;
}
// @lc code=end

