/*
 * @lc app=leetcode id=983 lang=cpp
 *
 * [983] Minimum Cost For Tickets
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
/*
WA，不能这么转移，last数组限制了转移条件，无法确定是转移还是继续持有票，dp应该保证当前dp依赖于以前的问题，直接转移
如果产生歧义 考虑其他的dp表达式
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int m = days.size();
        int n = costs.size();

        int dp[m][n], last[m][n];
        int cnt[3] = {1, 7, 30};

        for(int i = 0; i<3; ++i){
            dp[0][i] = costs[i];
            last[0][i] = days[0] + cnt[i];
        }
        for(int i = 1; i<m; ++i){
            int mini = INT_MAX;
            for(int k = 0; k <3; ++k){
                if(last[i-1][k] <= days[i]){
                    mini = min(mini, dp[i-1][k]);
                }
            }
            for(int k = 0; k<3; ++k){
                if(last[i-1][k] <= days[i]){
                    dp[i][k] = mini + costs[k];
                    last[i][k] = days[i] + cnt[k];
                }
                else{
                    dp[i][k] = dp[i-1][k];
                    last[i][k] = last[i-1][k];
                }
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i<3; ++i){
            ans = min(ans, dp[m-1][i]);
        }
        return ans;
    }
};
*/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans;
        int n = days[days.size()-1];
        int dp[n + 1];
        dp[0] = 0;
        vector<bool> set(n+1, false);
        for(auto day: days){
            set[day] = true;
        }
        for(int i = 1; i <=n; ++i){
            if(set[i] == false){
                dp[i] = dp[i-1];
                continue;
            }
            int onecost = dp[i-1] + costs[0];
            int sevencost = dp[max(i-7,0 )] + costs[1];
            int monthcost = dp[max(i-30, 0)] + costs[2];
            dp[i] = min(min(onecost, sevencost), monthcost);
        }
        return dp[n];
    }
};
// @lc code=end

int main(){
    Solution sol;
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2, 7, 15};
    cout<<sol.mincostTickets(days, costs);
    vector<int> days1 = {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs1 = {2, 7, 15};
    cout<<sol.mincostTickets(days1, costs1);

    vector<int> days2 = {4,5,9,11,14,16,17,19,21,22,24};
    vector<int> costs2 = {1,4,18};
    cout<<sol.mincostTickets(days2, costs2);

}
