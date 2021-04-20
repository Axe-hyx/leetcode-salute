/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int *father;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        if(edges.size() == 0) return ans;
        int n = edges.size();
        father = new int[n];
        for(int i = 0; i < n; ++i){
            father[i] = i;
        }
        for(int i = 0; i<n; ++i){
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;
            
            if(Find(u) == Find(v)){
                ans.push_back(u+1);
                ans.push_back(v+1);
                break;
            }
            Union(u, v);
        }
        return ans;
    }
    void Union(int u, int v){
        int fu = Find(u);
        int fv = Find(v);
        father[fu] = fv;
    }
    int Find(int x){
        if(x!=father[x]){
            father[x] = Find(father[x]);
        }
        return father[x];
    }
};
int main(int argc, char **argv){
    Solution sol;
    sol.
    return 0;
}
// @lc code=end
