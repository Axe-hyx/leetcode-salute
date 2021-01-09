/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int merge(vector<int> &nums, int l, int r){
        int mid = (r-l) / 2 + l;
        if(l == r){return 0;}
        int la = merge(nums, l, mid), ra = merge(nums, mid+1, r);
        int result = la + ra;

        for(int i = l, j = mid+1; i<=mid; ++i){
            while(j <= r && (long long)nums[i] > (long long)2 * nums[j])  ++j;
            result += j - mid - 1;
        }
        int p = l, q = mid+1;
        int n = r - l + 1;
        int num[n];
        memset(num, 0, sizeof(int) * n);
        int z = 0;

        // 归并排序必须开辟新空间。。
        while(p!=mid+1 && q!=r+1){
            if((long long)nums[p] <= (long long)nums[q]){
                num[z++] = nums[p++];
            }else{
                num[z++] = nums[q++];
            }
        }
        if(p == mid+1){
            while(q!=r+1){
                num[z++] = nums[q++];
            }
        }
        if(q == r+1){
            while(p!=mid+1){
                num[z++] = nums[p++];
            }
        }
        for(int i = 0; i<n;++i){
            nums[i+l] = num[i];
        }
        return result;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return n;
        return merge(nums, 0, n-1);
    }
};
int main(int argc, char **argv){
    Solution sol;
    vector<int> nums {1, 3, 2, 3, 1};
    cout<<sol.reversePairs(nums)<<endl;
    vector<int> nums1 {2, 4, 3, 5, 1};
    cout<<sol.reversePairs(nums1)<<endl;
    vector<int> nums2 {5, 4, 3, 2, 1};
    cout<<sol.reversePairs(nums2)<<endl;
    vector<int> nums3 {};
    cout<<sol.reversePairs(nums3)<<endl;
    vector<int> nums4 {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    cout<<sol.reversePairs(nums4)<<endl;
    vector<int> nums5 {233,2000000001,234,2000000006,235,2000000003,236,2000000007,237,2000000002,2000000005,233,233,233,233,233,2000000004};
    cout<<sol.reversePairs(nums5)<<endl;
    return 0;
}
// @lc code=end
