/*
 * @lc app=leetcode id=447 lang=cpp
 *
 * [447] Number of Boomerangs
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for(int i = 0; i<n;++i){
            unordered_map<int, int> map;
            for(int j = 0; j<n; ++j){
                if(i==j) continue;
                int dx = (points[i][0] - points[j][0]); 
                int dy = (points[i][1] - points[j][1]);
                int dis = dx * dx + dy * dy;
                ++map[dis];
            }
            for(auto x : map){
                ans += x.second * (x.second-1);
            }
        }
        return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    vector<vector<int>> points = {{0,0}, {1,0}, {2,0}};
    vector<vector<int>> points1 = {{1,1}, {2,2}, {3,3}};
    vector<vector<int>> points2 = {{1,1}};
    vector<vector<int>> points3 = {{0,0}, {1,0}, {2,0}, {1,1}};
    vector<vector<int>> points4 = {{0,0}, {1,0}, {-1,0}, {0,1}, {0,-1}};
    cout<<sol.numberOfBoomerangs(points4)<<endl;
    return 0;
}
// @lc code=end;
