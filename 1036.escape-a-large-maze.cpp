/*
 * @lc app=leetcode id=1036 lang=cpp
 *
 * [1036] Escape a Large Maze
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
        int upbound;
        int cnt;
        void dfs(int i, int j, bool &ans, const set<pair<int, int>> &bset, vector<int> & target,
                 set<pair<int,int>> &seen){
            if(bset.find({i,j}) != bset.end()) return; // block
            if(seen.find({i,j}) != seen.end()) return;
            seen.insert({i,j});
            ++cnt;
            if(cnt > upbound || target[0] == i && target[1] == j){
                ans = true;
                return;
            }
            static vector<vector<int>> direction ={{-1,0}, {0,-1}, {0,1}, {1,0}};
            for(auto d : direction){
                int x = d[0] + i, y = d[1] + j;
                if(x<0 || x >= 1e6 || y<0 || y >= 1e6){
                    continue;
                }
                dfs(x, y, ans, bset, target, seen);
                if(ans) return;
            }
        }
        bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {

            upbound = blocked.size() != 0 ? blocked.size() * (blocked.size() - 1) / 2 : 1;
            set<pair<int, int>> bset;
            set<pair<int, int>> seen;
            for(int i = 0; i<blocked.size(); ++i){
                bset.insert({blocked[i][0], blocked[i][1]});
            }
            cnt = 0;
            bool sans = false;
            dfs(source[0], source[1], sans, bset, target, seen);
            bool tans = false;
            seen.clear();
            cnt = 0;
            dfs(target[0], target[1], tans, bset, source, seen);
            if(sans == true && tans == true){return true;} else return false;
        }
};
int main(int argc, char **argv){
    Solution sol;
    {
        vector<vector<int>> blocked {{0,1}, {1,0}};
        vector<int> sources {{0,0}};
        vector<int> targets {0,2};
        cout<<sol.isEscapePossible(blocked, sources, targets)<<endl;
    }
    {
        vector<vector<int>> blocked {};
        vector<int> sources {0,0};
        vector<int> targets {999999,999999};
        cout<<sol.isEscapePossible(blocked, sources, targets)<<endl;
    }
    {
        vector<vector<int>> blocked {{0,999991},{0,999993},{0,999996},{1,999996},{1,999997},{1,999998},{1,999999}};
        vector<int> sources {0,999997};
        vector<int> targets {0,2};
        cout<<sol.isEscapePossible(blocked, sources, targets)<<endl;
    }
    return 0;
}
// @lc code=end
