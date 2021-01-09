/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       for(int i = 1; i< triangle.size(); ++i){
           for(int k = 0; k<triangle[i].size(); ++k){
               int l = k-1;
               int mini = INT_MAX;
               if(l>=0)
                   mini = min(mini, triangle[i-1][l]);
               int r = k;
               if(r<triangle[i-1].size())
                   mini = min(mini, triangle[i-1][r]);
               triangle[i][k] = mini + triangle[i][k];
           }
       }

       int mini = INT_MAX;
       for(auto i : triangle[triangle.size()-1]){
            mini = min(i, mini);
       }
       return mini;
    }
};
// @lc code=end
int main(){
    Solution sol;
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    cout<<sol.minimumTotal(triangle);
    return 0;
}
