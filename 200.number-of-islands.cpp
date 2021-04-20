/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
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
  void dfs(vector<vector<bool>> &seen, int i, int j, int &ans,
           vector<vector<char>> &grid) {
    vector<vector<int>> delta = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (auto d : delta) {
      int x = i + d[0], y = j + d[1];
      if (x < 0 || x >= n || y < 0 || y >= m) {
        continue;
      }
      if (grid[x][y] == '1' && !seen[x][y]) {
        seen[x][y] = true;
        dfs(seen, x, y, ans, grid);
      }
    }
  }
  int numIslands(vector<vector<char>> &grid) {
    n = grid.size();
    if (!n)
      return 0;
    m = grid[0].size();
    int ans = 0;
    vector<vector<bool>> seen(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
      for (int k = 0; k < m; ++k) {
        if (grid[i][k] == '1' && seen[i][k] == false) {
          dfs(seen, i, k, ans, grid);
          ++ans;
        }
      }
    }
    return ans;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  /*
  {
    vector<vector<char>> island = {{'1', '1', '1', '1', '0'},
                                   {'1', '1', '0', '1', '0'},
                                   {'1', '1', '0', '0', '0'},
                                   {'0', '0', '0', '0', '0'}};
    cout << sol.numIslands(island);
  }
  */
  {
    vector<vector<char>> island = {{'1', '1', '0', '0', '0'},
                                   {'1', '1', '0', '0', '0'},
                                   {'0', '0', '1', '0', '0'},
                                   {'0', '0', '0', '1', '1'}};
    cout << sol.numIslands(island);
  }
  return 0;
}
// @lc code=end
