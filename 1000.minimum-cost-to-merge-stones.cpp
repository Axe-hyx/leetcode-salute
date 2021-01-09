/*
 * @lc app=leetcode id=1000 lang=cpp
 *
 * [1000] Minimum Cost to Merge Stones
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int dp[30][30][31];
        int len = stones.size();
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < len; ++j){
                for(int k = 0; k<=K; ++k){
                    dp[i][j][k] = INT_MAX;
                }
            }
        }
        if((len-1) % (K-1) !=0) return -1;
        for(int i = 0; i<len;++i){
            dp[i][i][1] = 0;
        }
        int sum[30];
        sum[0] = stones[0];
        for(int i = 1; i<len; ++i){
            sum[i] = sum[i-1] + stones[i];
        }
        for(int l = 2; l<=len; ++l){
            for(int i = 0; i<=len-l; ++i){
                int j = i+l-1;
                for(int t = i; t<j; ++t){
                    for(int k = 2; k<=K; ++k){
                            if(dp[i][t][k-1] == INT_MAX || dp[t+1][j][1] == INT_MAX) continue;
                            dp[i][j][k] = min(dp[i][j][k],  dp[i][t][k-1] + dp[t+1][j][1]);
                    }
                    if(dp[i][j][K] != INT_MAX) // 合并才计分
                        dp[i][j][1] = dp[i][j][K] + sum[j] - sum[i] + stones[i];
                    // 子问题的定义
                    // 冗余，左边k-2，右边2 和 左边k-1，右边1 是一样的
                    /*
                       for(int k = 2; k<=K; ++k){
                       for(int le = 1; le < k; ++le){
                       if(dp[i][t][le] == INT_MAX || dp[t+1][j][k-le] == INT_MAX) continue;
                       dp[i][j][k] = min(dp[i][j][k],  dp[i][t][le] + dp[t+1][j][k-le]);
                       }
                       }
                       if(dp[i][j][K] != INT_MAX) // 合并才计分
                       dp[i][j][1] = dp[i][j][K] + sum[j] - sum[i] + stones[i];
                     * */

                }    
                printf("%d %d %d\n", i, j, dp[i][j][1]);
            }
        }
        return dp[0][len-1][1];
    }
};
int main(){
    Solution sol;
    vector<int> stones = {3,2,4,1};
    std::cout<<sol.mergeStones(stones, 2)<<std::endl;
    vector<int> stones1 = {3,2,4,1};
    std::cout<<sol.mergeStones(stones1, 3)<<std::endl;
    vector<int> stones2 = {3,5,1,2,6};
    std::cout<<sol.mergeStones(stones2, 3)<<std::endl;
    vector<int> stones3 = {24,21,84,61,75,26,63,54,94,83,53,17,27,49,41,75,1,93,61,88,29,99,25,90,100,13,50,38,2,30};
    std::cout<<sol.mergeStones(stones3, 30)<<std::endl;
    return 0;
}
// @lc code=end

