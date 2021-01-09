/*
 * @lc app=leetcode id=1220 lang=cpp
 *
 * [1220] Count Vowels Permutation
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<unsigned int>> map={{2}, {1,3}, {1,2,4,5}, {3,5}, {1}};
        // 1e9 + 7 一定要配 unsigned
        unsigned int dp[6][n];
        memset(dp, 0, sizeof(unsigned int) * 6 * n);
        for(int i = 1; i<=5; ++i){
            dp[i][0] = 1;
        }
        for(int i = 1; i<n;++i){
            for(int k = 1; k<=5; ++k){
                for(auto it : map[k-1]){
                    dp[k][i] += dp[it][i-1];
                    // 模(unsigned) 可有可无
                    dp[k][i] %= (unsigned int)1e9+7;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i<=5; ++i){
            ans += dp[i][n-1];
            ans %= (unsigned int)1e9+7;
        }
        return ans;
    }
};
int main(){
    Solution sol;
    cout<<sol.countVowelPermutation(1)<<endl;
    cout<<sol.countVowelPermutation(2)<<endl;
    cout<<sol.countVowelPermutation(5)<<endl;
    cout<<sol.countVowelPermutation(144)<<endl;
    return 0;
}
// @lc code=end

