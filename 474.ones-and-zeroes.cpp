/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int findMaxForm(vector<string>& strs, int m, int n) {
            vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
            dp[0][0] = 0;
            int ans = -1;
            for(int s=0;s<strs.size(); ++s){
                int zero = 0;
                for(int n = 0; n<strs[s].size();++n){
                    if(strs[s][n]=='0')
                        zero+=1;
                }
                int one = strs[s].length() - zero;
                // 反向更新，少存储旧的状态
                // 边界i=n 时k!=0，所以边界放宽:
                for(int i = m; i>=0; --i){
                    for(int k = n; k>=0;--k){
                        if(i>=zero && k>= one){
                            if(dp[i-zero][k-one] != -1){
                                dp[i][k] = max(dp[i][k],dp[i-zero][k-one] + 1);
                            }
                        }
                    }
                }
            }
            for(int i = 0; i<=m; ++i){
                for(int k = 0; k<=n;++k){
                    ans = max(ans, dp[i][k]);
                }}
            return  ans;
        }
};
// @lc code=end

int main(){
    Solution sol;
    vector<string> strs={"10","0001","111001","1","0"};
    int m = 5, n = 3;
    cout<<sol.findMaxForm(strs, m, n);

    vector<string> strs1={"10","0","1"};
    int m1 = 1, n1 = 1;
    cout<<sol.findMaxForm(strs1, m1, n1);
    return 0;
}
