/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
    public:
        int knightDialer(int N) {
            vector<vector<int>> map={{4,6}, {6,8},{7,9}, {4,8}, {3,9,0}, {}, {1,7,0}, {2,6}, {1,3}, {2,4}, {4,6}};
            vector<int> dp(10, 1);
            for(int i = 1; i<N;++i){
                vector<int> t(10, 0);
                for(int k = 0; k<10; ++k){
                    for(auto m : map[k]){
                        t[k] += dp[m];
                        t[k] %= (int)(1e9+7);
                    }
                }
                dp = t;
            }
            int ans = 0;
            for(auto a : dp){
                ans = (ans + a) %(int)(1e9+7);
            }
            return ans;
        }
};
int main(){ 
    Solution sol;
    cout<<sol.knightDialer(1)<<endl;
    cout<<sol.knightDialer(2)<<endl;
    cout<<sol.knightDialer(3)<<endl;
    cout<<sol.knightDialer(5000)<<endl;

    return 0;
}
// @lc code=end

