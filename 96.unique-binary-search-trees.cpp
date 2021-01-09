/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int numTrees(int n) {
        int dp [n+1];
        memset(dp, 0, sizeof(int) * (n+1));
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i<=n;++i){
            for(int k = 0; k<i;++k){
                dp[i] += dp[k] * dp[i-k-1];
            }
        }
        return dp[n];
    }
};
int main(){
    Solution sol;
    std::cout<<sol.numTrees(1)<<std::endl;
    std::cout<<sol.numTrees(2)<<std::endl;
    std::cout<<sol.numTrees(3)<<std::endl;
    std::cout<<sol.numTrees(4)<<std::endl;
    std::cout<<sol.numTrees(5)<<std::endl;
    std::cout<<sol.numTrees(5)<<std::endl;
    std::cout<<sol.numTrees(5)<<std::endl;
    std::cout<<sol.numTrees(5)<<std::endl;
    std::cout<<sol.numTrees(10)<<std::endl;
    return 0;
}
// @lc code=end

