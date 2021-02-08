/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int *father;
    int n;
    int cnt;
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        if(n==0) return 0;
        father = new int[n * n * 4];
        memset(father, 0, sizeof(int) * n * n * 4);
        cnt = n * n * 4;
        for(int i = 0; i<n*n*4;++i){
            father[i] = i;
        }

        for(int i = 0; i<n; ++i){
            for(int j = 0; j<n; ++j){
                if(i > 0){
                    Union(idx(i-1, j, 2), idx(i, j, 0));
                }
                if(j > 0){
                    Union(idx(i, j-1, 1), idx(i, j, 3));
                }
                if(grid[i][j] != '/'){
                    Union(idx(i, j, 0), idx(i, j, 1));
                    Union(idx(i, j, 2), idx(i, j, 3));
                }
                if(grid[i][j] !='\\'){
                    // WA: 并查集保证合并时，要从
                    // B树的叶子与A树进行合并
                    Union(idx(i, j, 2), idx(i, j, 1));
                    Union(idx(i, j, 0), idx(i, j, 3));
                }
            }
        }
        return cnt;
    }
    int idx(int i, int j, int k){
        return (i * n + j) * 4 + k;
    }
    int Find(int x){
        if(father[x] != x){
            father[x] = Find(father[x]);
        }
        return father[x];
    }
    void Union(int u, int v){
        // WA: 进行压缩，fu = Find，而不是fu = father[]
        int fu = Find(u);
        int fv = Find(v);
        if(fu != fv){
            father[fv]= fu;
            --cnt;
        }
    }
};
int main(int argc, char **argv){
    Solution sol;
    {
        vector<string> grid = {" "};
        //cout<<sol.regionsBySlashes(grid)<<endl;
    }
    {
        vector<string> grid = {" /", "/ "};
        cout<<sol.regionsBySlashes(grid)<<endl;
    }
    return 0;
}
// @lc code=end
