/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(int) * (n+1) * (m+1));
        for(int i = 1; i<=m; ++i){
            dp[0][i] = dp[0][i-1] + s2[i-1];
        }
        for(int i = 1; i<=n; ++i){
            dp[i][0] = dp[i-1][0] + s1[i-1];
            for(int j = 1; j<=m; ++j){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                }
            }
        }
        return dp[n][m];
    }

};
int main(){
    Solution sol;
    string s1 = "sea", t1 = "eat";
    cout<<sol.minimumDeleteSum(s1, t1)<<endl;
    string s2 = "delete", t2 = "leet";
    cout<<sol.minimumDeleteSum(s2, t2)<<endl;
    string s3 = "kslcclpmfd", t3 = "guvjxozrjvzhe";
    cout<<sol.minimumDeleteSum(s3, t3)<<endl;
    return 0;
}
// @lc code=end

