/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i = 2; i<=n; ++i){
            dp[i]=0;
            for(int st =1; st <=2; st++){
                dp[i] += dp[i-st];
            }
        }
        return dp[n];
    }
};
int main(){
    Solution sol;
    cout<<sol.climbStairs(1)<<endl;
    cout<<sol.climbStairs(2)<<endl;
    cout<<sol.climbStairs(3)<<endl;
    return 0;
}
// @lc code=end

