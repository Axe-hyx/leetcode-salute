/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size(); 
       if(n==0) return 0;
       int lessl[n];
       int lessr[n];
       for(int i = 0; i<n; ++i){ // 0-n-1
           int p = i - 1;
           while(p!=-1 && heights[p] >= heights[i]){
               p = lessl[p];
           }
           lessl[i] = p;
       }
       for(int i = n-1; i>=0; --i){
           int p = i+1;
           while(p != n && heights[p] >= heights[i]){
               p = lessr[p];
           }
           lessr[i] = p;
       }
       int ans = 0;
       for(int i = 0; i<n; ++i){
           ans = max(ans, (lessr[i] - lessl[i]-1) * heights[i]);
       }
       return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout<<sol.largestRectangleArea(heights)<<endl;
    vector<int> heights1 = {};
    cout<<sol.largestRectangleArea(heights1)<<endl;
    return 0;
}
// @lc code=end

