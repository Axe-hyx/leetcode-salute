/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int *pms = new int[nums.size() + 2];
        int n = 1;
        for(auto x : nums){
            pms[n++] = x;
        }
        pms[0] = pms[n++] = 1;
        int dp[n][n];
        memset(dp, 0, sizeof(int) * n * n);

        for(int k = 2; k < n; ++k){
            for(int left = 0; left < n - k; ++left){
                int right = left + k;
                for(int tar = left + 1; tar < right; ++tar){
                    dp[left][right] = max(dp[left][right], dp[left][tar] + dp[tar][right] + pms[tar]
                            * pms[left] * pms[right]);
                }
            }
        }
        delete []pms;
        return dp[0][n-1];
    }
};
int main(){
    Solution sol;
    std::vector<int> nums = {3,1,5,8};
    std::cout<<sol.maxCoins(nums)<<endl;
    return 0;
}
// @lc code=end

