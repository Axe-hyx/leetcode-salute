/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // trick here, sum, index
        unordered_map<int, int> map;
        int sum = 0;
        for(int i = 0; i<nums.size();++i){
            sum += nums[i];
            sum %=k;
            if(map.find(sum)!=map.end()){
                return true;
            }else{
                map[sum] = i;
            }
        }
        return false;
    }
};
// @lc code=end

