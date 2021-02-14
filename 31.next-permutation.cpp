/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        bool find = false;
        int k;
        for(k = n-2; k>=0; --k){
            if(nums[k+1] > nums[k]) // 上坡
            {
                find = true;
                break;
            }
        }
        if(!find) {
            sort(nums.begin(), nums.end());
            return;
        }
        int i;
        for(i = n-1; i>=k; --i){
            if(nums[i] >nums[k])
                break;
        }
        swap(nums[k], nums[i]); // 没有上坡了，插入[k]，[k+1]开始的下坡变上坡
        reverse(nums.begin() + k + 1, nums.end());
    }
};
int main(int argc, char **argv){
    Solution sol;
    {
        vector<int> nums {1, 2, 3};
        sol.nextPermutation(nums);
        for(auto v : nums){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    {
        vector<int> nums {3, 2, 1};
        sol.nextPermutation(nums);
        for(auto v : nums){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    {
        vector<int> nums {1, 1, 5};
        sol.nextPermutation(nums);
        for(auto v : nums){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    {
        vector<int> nums {4, 5, 4, 3};
        sol.nextPermutation(nums);
        for(auto v : nums){
            cout<<v<<" ";
        }
        cout<<endl;
    }{
        vector<int> nums {1, 5, 4, 3};
        sol.nextPermutation(nums);
        for(auto v : nums){
            cout<<v<<" ";
        }
        cout<<endl;
    }

    return 0;
}
// @lc code=end
