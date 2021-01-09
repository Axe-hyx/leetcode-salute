/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    unsigned int dp[1001];
    const int MOD = 1e9 + 7;
    int numTilings(int N) {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i<=N;++i){
            dp[i] = ((2 * dp[i-1])%MOD + dp[i-3])%MOD;
        }
        return dp[N];
    }
};
int main(){
    Solution sol;
    cout<<sol.numTilings(3)<<endl;
    cout<<sol.numTilings(4)<<endl;
    cout<<sol.numTilings(5)<<endl;
    cout<<sol.numTilings(500)<<endl;
    cout<<sol.numTilings(1000)<<endl;
    return 0;
}
// @lc code=end

