/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
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
    int n, m;
    void dfs(int i, int j, vector<vector<bool>> &seen, vector<vector<int>> & matrix){
        if(seen[i][j]) return;

        vector<vector<int>> dir = {{-1,0}, {0, -1}, {0,1}, {1,0}};
        seen[i][j] = true;
        for(auto d : dir)
        {
            int x = d[0] + i, y = d[1] + j;
            if(x < 0 || x >= n || y<0 || y>=m){
                continue;
            }
            if(!seen[x][y] && matrix[x][y] >= matrix[i][j]){
                dfs(x, y, seen, matrix);
            }
        }   
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        n = matrix.size();
        if(!n) return {};
        m = matrix[0].size();
        vector<vector<bool>> pA (n, vector<bool>(m, false));
        vector<vector<bool>> pB (n, vector<bool>(m, false));
        for(int i = 0; i<n; ++i){
            dfs(i, 0, pA, matrix);
            dfs(i, m-1, pB, matrix);
        }
        for(int j = 0; j<m; ++j){
            dfs(0, j, pA, matrix);
            dfs(n-1, j, pB, matrix);
        }
        vector<vector<int>> ans;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(pA[i][j] == true && pB[i][j] == true){
                    ans.push_back({i,j});
                }
            }
        }return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    {
        vector<vector<int>> grid {
            {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}
        };
        for(auto i : sol.pacificAtlantic(grid)){
            for(auto val : i){
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
    {
        vector<vector<int>> grid {
            {10,10,10}, {10,1,10}, {10,10,10}
        };
        for(auto i : sol.pacificAtlantic(grid)){
            for(auto val : i){
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
// @lc code=end
