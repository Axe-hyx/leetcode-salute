/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        int lastsign, sign;
        int len = n;
        for(int i = 1; i<n; ++i){
            if(nums[i] == nums[i-1]){
                --len;
            }else{
                lastsign = sign;            
                sign = nums[i] > nums[i-1] ? 1 : -1;
                if(lastsign == sign && i != 1){
                    --len;
                }
            }
        }
        return len;
    }
};
int main(int argc, char **argv){
    Solution sol;
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    cout<<sol.wiggleMaxLength(nums)<<endl;
    vector<int> nums1 = {1,17,5,10,13,15,10,5,16,8};
    cout<<sol.wiggleMaxLength(nums1)<<endl;
    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout<<sol.wiggleMaxLength(nums2)<<endl;
    vector<int> nums3 = {0, 0};
    cout<<sol.wiggleMaxLength(nums3)<<endl;
    vector<int> nums4 = {3,3,3,2,5};
    cout<<sol.wiggleMaxLength(nums4)<<endl;
    return 0;
}
// @lc code=end
