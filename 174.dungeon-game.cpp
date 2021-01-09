/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        dp[n][m-1] = 1;
        dp[n-1][m] = 1;
    
        
        
        for(int i = n-1; i>=0; --i){
            for(int j = m-1; j>=0; --j){
                // 因为这里是int_max，所以初始值直接设INT_MAX
                int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = need <=0? 1: need;
            }
        }
        return dp[0][0];
        /*
        int n = dungeon.size();
        int m = dungeon[0].size();
        int curr[n][m];
        int low[n][m];
        if(n == 0) return 1;
        curr[0][0] = dungeon[0][0];
        low[0][0] = curr[0][0] <= 0 ? -curr[0][0] + 1 : 1;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                int hp = INT_MAX;
                //过去最低血量
                if(i>0 && low[i-1][j] < hp){
                    hp = low[i-1][j];
                    curr[i][j] = curr[i-1][j];
                }
                if(j>0 && low[i][j-1] < hp){
                    hp = low[i][j-1];
                    curr[i][j] = curr[i][j-1];
                }
                if(i!=0 && j != 0){
                    if(low[i-1][j]==low[i][j-1])
                        curr[i][j]= max(curr[i][j-1], curr[i-1][j]);
                }
                if(i!=0 || j !=0){
                    //FIX 两个转移hp相等
                    curr[i][j] += dungeon[i][j];
                    low[i][j] = curr[i][j]<=0? max(abs(curr[i][j])+1,hp):hp;
                }
            }
        }    

        return low[n-1][m-1];
        */
    }
};
int main(){
    vector<vector<int>> dungeon={{-2, -3, 3}, {-5,-10, 1}, {10,30,-5}};
    vector<vector<int>> dungeon1={{0}};
    vector<vector<int>> dungeon2={{100}};
    vector<vector<int>> dungeon3={{0,0,0}, {1,1,-1}};
    // 转移逻辑不对考虑curr,hp. {-1,2} {1,3} 当前位置-3,按照最小hp转移，2 更新后为5,实际上应该为3
    // 告诉我们不能正向判断是否产生转移，考虑反着循环
    vector<vector<int>> dungeon4={{1,-3,3},{0,-2,0},{-3,-3,-3}};
    vector<vector<int>> dungeon5={{0,-3}, {-10,0}};
    vector<vector<int>> dungeon6={{2},{1}};
    Solution sol;
    cout<<sol.calculateMinimumHP(dungeon)<<endl;
    cout<<sol.calculateMinimumHP(dungeon1)<<endl;
    cout<<sol.calculateMinimumHP(dungeon2)<<endl;
    cout<<sol.calculateMinimumHP(dungeon3)<<endl;
    cout<<sol.calculateMinimumHP(dungeon4)<<endl;
    cout<<sol.calculateMinimumHP(dungeon5)<<endl;
    cout<<sol.calculateMinimumHP(dungeon6)<<endl;
    return 0;
}
// @lc code=end

