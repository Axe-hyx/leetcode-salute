/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        struct val{
            int l, r, m, s;
            val(int l, int r, int m, int s):l(l), r(r), m(m), s(s){};
        };
        val sub(const vector<int> nums, int k, int n){
            if(n == 1) {
                return val(nums[k],nums[k],nums[k], nums[k]);
            }
            // reverse thinking,想想m可能从m 或者 l.r + r.l 而来
            // l.r 或 r.l 需要 s
            val la = sub(nums, k, n/2), ra = sub(nums, k+n/2, n - n/2);
            int l = max(la.l, la.s + ra.l);
            int r = max(ra.r, ra.s + la.r);
            int s = la.s + ra.s;
            int m = max(la.m, max(ra.m, la.r + ra.l));
            val a = val(l,r,m,s);
            return a;
        }
        int maxSubArray(vector<int>& nums) {
            int n = nums.size();
            return sub(nums, 0, n).m;
        }
};
int main(){
    Solution sol;
    vector<int> num = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<<sol.maxSubArray(num)<<endl;
    vector<int> num1 = {1};
    cout<<sol.maxSubArray(num1)<<endl;
    vector<int> num2 = {0};
    cout<<sol.maxSubArray(num2)<<endl;
    vector<int> num3 = {-1};
    cout<<sol.maxSubArray(num3)<<endl;
    vector<int> num4 = {-2147483647};
    cout<<sol.maxSubArray(num4)<<endl;
    return 0;
}
// @lc code=end

