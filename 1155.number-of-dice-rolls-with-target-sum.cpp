/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int numRollsToTarget(int d, int f, int target) {
            int dp[d+1][target +  1];
            memset(dp, 0 , sizeof(int) * (target + 1) * (d + 1));
            dp[0][0] = 1;
            for(int i = 1; i <= d; ++i){
                //双重循环 枚举已有 和 转移来的情况
                for(int already = 0; already <=target; ++already){
                    for(int fi = 1; fi <=f; ++fi){
                        if(already - fi >=0){
                            dp[i][already] += dp[i-1][already - fi];
                            dp[i][already] %= (int)1e9 + 7;
                        }
                    }
                }
            }
            return dp[d][target];
        }
};
int main(){
    Solution sol;
    cout<<sol.numRollsToTarget(1, 6, 3)<<endl;
    cout<<sol.numRollsToTarget(2, 6, 7)<<endl;
    cout<<sol.numRollsToTarget(2, 5, 10)<<endl;
    cout<<sol.numRollsToTarget(1, 2, 3)<<endl;
    cout<<sol.numRollsToTarget(30, 30, 500)<<endl;
    return 0;
}
// @lc code=end

