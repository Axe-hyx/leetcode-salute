/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq;
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i<n; ++i){
            while(!deq.empty() && deq.front() < i-k + 1) {
                deq.pop_front();
            }
            while(!deq.empty() && nums[deq.back()] < nums[i]){
                deq.pop_back();
            }
            deq.push_back(i);
            if(i >=k-1)
                ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    vector<int> nums1 = {1,3,-1,3,5,3,6,7};
    auto v1 = sol.maxSlidingWindow(nums1, 3);
    for(auto v : v1){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;
    vector<int> nums2 = {1, -1};
    auto v2 = sol.maxSlidingWindow(nums2, 1);
    for(auto v : v2){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
// @lc code=end
