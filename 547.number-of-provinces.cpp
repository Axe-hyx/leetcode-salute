/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Remove Boxes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int *father;
    vector<int> size;
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.size() == 0) return 0;
        int n = isConnected[0].size();  
        father = new int[n];
        size.resize(n);
        for(int i = 0; i<n; ++i){
            father[i] = i;
            size[i] = 1;
        }
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<i; ++j){
                if(isConnected[i][j] == 1){
                    Union(i, j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i<n;++i){
            if(father[i] == i){
                ++ans;
            }
        }
        return ans;
    }
    void Union(int u, int v){
        int fu = Find(u);
        int fv = Find(v);
        if(fu == fv) return;
        if(size[fu] < size[fv])
            swap(fu, fv);
        father[fv] = fu;
        size[fu] += size[fv];
    }
    int Find(int x){
        // 只用if 判断就行，之前的路径已经压缩好了
        if(x != father[x]){
            father[x] = Find(father[x]);
        }
        return father[x];
    }
};
int main(){
    Solution sol;
    vector<vector<int>> t {{1,1,1}, {1,1,1}, {1,1,1}};
    cout<<sol.findCircleNum(t)<<endl;
    return 0;
}
// @lc code=end

