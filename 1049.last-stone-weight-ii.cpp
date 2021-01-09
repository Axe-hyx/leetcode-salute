/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        
        int sum = 0;
        for(auto i : stones){
            sum += i;
        }
        vector<vector<int>>dp(n, vector<int>(sum/2+2, 0));
        dp[0][stones[0]] = 1;
        dp[0][0] = 1;
        for(int i = 1; i<n;++i){
            for(int k = 0; k<=sum/2+1; ++k){
                dp[i][k] = dp[i-1][k];
                if(k >= stones[i]){
                    if(dp[i-1][k-stones[i]]!=0)
                        dp[i][k] = 1;
                }
            }
        }
        int i;
        for(i = sum/2; i>0; --i){
            cout<<dp[n-1][i]<<" "<<i<<endl;
            if(dp[n-1][i] !=0) break;
        }
        return abs(i-(sum-i));
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<int> stones = {1,1,4,2,2};
    cout<<sol.lastStoneWeightII(stones);
    return 0;
}
