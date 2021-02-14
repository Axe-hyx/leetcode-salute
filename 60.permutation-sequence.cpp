/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
    public:
        // 另一种方法，第k位有k-1！种选择，ex：4位有6种排列，根据k推出是哪一个数字
        void nextP(vector<int> &nums){
            int n = nums.size();
            int k;
            if(n < 2) return;
            for(k = n-2; k>=0; --k){
                if(nums[k+1] > nums[k]){
                    break;
                }
            }
            if(k<0){

            }else{
                int l;
                for(l = n-1; l>=k; --l){
                    if(nums[l] > nums[k]){
                        break;
                    }
                }
                swap(nums[k], nums[l]);
                reverse(nums.begin() + k + 1, nums.end());
            }
        }
        string getPermutation(int n, int k) {
            vector<int> ans;
            for(int i = 0; i<n; ++i){
                ans.push_back(i+1);
            }
            while(--k){
                nextP(ans);
            }
            int sum = 0;
            for(int i = 0; i<n; ++i){
                sum = sum * 10 + ans[i];
            }

            return to_string(sum);
        }
};
int main(int argc, char **argv){
    Solution sol;
    { cout << sol.getPermutation(3, 3) << endl; }
    { cout << sol.getPermutation(4, 9) << endl; }
    { cout << sol.getPermutation(3, 1) << endl; }
    return 0;
}
// @lc code=end
