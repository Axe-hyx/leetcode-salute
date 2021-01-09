/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start

// 非常trick，分类讨论，然后转移，枚举情况
class Solution {
public:
    int minSteps(int n) {
        int dp[n + 1];
        if(n==1) return 0;
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;
        for(int i = 3; i<=n; ++i){
            if(i%2==0){
                dp[i] = dp[i/2] + 2;
            }else{
                int j;
                for(j = 3; j<=n; ++j){
                    if(i % j ==0){
                        break;
                    }
                }
                dp[i] = dp[i/j] + j;
            }
        }

        return dp[n];
    }
};
// @lc code=end

int main(){
    Solution sol;
    sol.minSteps(4);
    return 0;
}
