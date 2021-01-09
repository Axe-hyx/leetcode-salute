/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    // divide and conque
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int k = (n+ m + 1) / 2;
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        int l = 0, r = 0;
        double ans = 0;
        while(k!=1){
            int sl, sr, ml, mr;
            sl = l ==n ? n+1: l + k/2 >= n ? n : l + k/2;
            sr = r ==m ? m+1: r + k/2 >= m ? m : r + k/2;
            if(nums1[sl-1] <= nums2[sr-1]){
                k -= sl - l;
                l += sl - l;
            }else{
                k -= sr - r;
                r += sr - r;
            }
        }
        if(nums1[l] <= nums2[r]){
            ans += nums1[l];
            l++;
        }
        else{
            ans += nums2[r];
            r++;
        }
        if((n+m)%2==0){
            ans += min(nums1[l], nums2[r]);
            ans /= 2.0;
        }
        return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    vector<int> s1={1,3};
    vector<int> t1={2};
    //cout<<sol.findMedianSortedArrays(s1, t1)<<endl;
    vector<int> s2={1,2};
    vector<int> t2={3, 4};
    //cout<<sol.findMedianSortedArrays(s2, t2)<<endl;
    vector<int> s3={0, 0};
    vector<int> t3={0, 0};
    //cout<<sol.findMedianSortedArrays(s3, t3)<<endl;
    vector<int> s4={};
    vector<int> t4={1};
    //cout<<sol.findMedianSortedArrays(s4, t4)<<endl;
    vector<int> s5={2};
    vector<int> t5={};
    //cout<<sol.findMedianSortedArrays(s5, t5)<<endl;
    vector<int> s6={};
    vector<int> t6={1,2,3,4};
    cout<<sol.findMedianSortedArrays(s6, t6)<<endl;
    return 0;
}
// @lc code=end

