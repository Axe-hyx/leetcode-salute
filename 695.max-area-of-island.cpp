/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * {695} Max Area of Island
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "helper.h"
#endif
// Time Complexity: O()
// Space Complexity: O()
class Solution {
    public:
        vector<vector<int>> dir = {{-1,0}, {0, -1}, {0, 1}, {1,0}};
        int n, m;
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            n = grid.size();
            if(!n) return 0;
            m = grid[0].size();
            int ans = 0;
            for(int i = 0; i<n; ++i){
                for(int k = 0; k <m; ++k){
                    int cnt = 0;
                    if(grid[i][k] == 1){
                        stack<pair<int, int>> vis;
                        vis.push({i,k});
                        cnt = 1;
                        grid[i][k] = 0;
                        while(!vis.empty())
                        {
                            pair<int, int> top = vis.top();
                            vis.pop();
                            for(auto d : dir){
                                int x = top.first + d[0], y = top.second + d[1];
                                if(x<0 || x >= n || y < 0 || y >= m){
                                    continue;
                                }
                                if(grid[x][y] == 1){
                                    grid[x][y] = 0;
                                    ++cnt; 
                                    vis.push({x,y});
                                }
                            }
                        }

                        ans = max(ans, cnt);
                    }
                }
            }
            return ans;
        }
};
int main(int argc, char **argv){
    Solution sol;
    {
        vector<vector<int>> grid {{0,0,1,0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,1,1,0,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,1,1,0,0,1,0,1,0,0},
            {0,1,0,0,1,1,0,0,1,1,1,0,0},
            {0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,0,0,0,0,0,0,1,1,0,0,0,0}};
        cout<<sol.maxAreaOfIsland(grid);
        return 0;
    }
}
// @lc code=end
