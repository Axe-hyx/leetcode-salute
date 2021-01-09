/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // 注意是找最长个数，不是最长的长度，双层for循环，枚举可以转移的条件
        // dp[i] 依赖于之前的数组，不是单个premax值
        
        int n = nums.size();
        if(n==0) return 0;
        int len[n], cnt[n];
        int maxlen = 0;
        int ans = 0;
        for(int i = 0; i<n; ++i){
            len[i] = cnt[i] = 1;
            for(int j = 0; j<i; ++j){
                if(nums[i]>nums[j]){
                    if(len[i]==len[j] + 1){
                        cnt[i] += cnt[j];
                    }
                    if(len[i] < len[j] + 1){
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if(maxlen == len[i]){
                ans += cnt[i];
            }
            if(maxlen < len[i]){
                maxlen = len[i];
                ans = cnt[i];
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> nums={1,3,5,4,7};
    cout<<sol.findNumberOfLIS(nums)<<endl;
    vector<int> nums1={2,2,2,2,2};
    cout<<sol.findNumberOfLIS(nums1)<<endl;
    return 0;
}
// @lc code=end

