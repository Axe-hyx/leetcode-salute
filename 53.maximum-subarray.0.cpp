/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n; ++i){
            sum += nums[i];
            if(sum > ans)
                ans = sum;
            if(sum < 0)
                sum = 0;
        }
        return ans;

    }
};
int main(int argc, char **argv){
    Solution sol;
    vector<int> nums {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<<sol.maxSubArray(nums)<<endl;
    vector<int> nums1 {1};
    cout<<sol.maxSubArray(nums1)<<endl;
    vector<int> nums2 {0};
    cout<<sol.maxSubArray(nums2)<<endl;
    vector<int> nums3 {-1};
    cout<<sol.maxSubArray(nums3)<<endl;
    vector<int> nums4 {-2147483647};
    cout<<sol.maxSubArray(nums4)<<endl;
    return 0;
}
// @lc code=end
