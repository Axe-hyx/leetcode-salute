/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */
#include <bits/stdc++.h>

using namespace std;
// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        for(int k = 1; k<=sqrt(n);++k){
            dp[k*k] = 1;
        }
        for(int i = 1; i<=n; ++i){
            if(dp[i]==0){
                int mini = INT_MAX;
                for(int k =sqrt(i); k>0; --k){
                    if(i >= k *k)
                        mini = min(mini, dp[i-k*k]+1);
                }
                dp[i] = mini;
            }
        }
        return dp[n];
    }

};
// @lc code=end
//
int main(){
    Solution sol;
    for(int i = 0; i< 20;++i)
        cout<<sol.numSquares(i)<<" ";
    return 0;

}
