/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int dp[n][n];
        int maxs[n][n];
        memset(dp, 0, sizeof(int) * n *n);
        for(int i = 0; i<n; ++i){
            maxs[i][i] = arr[i];
        }
        for(int l = 1; l<n; ++l){
            for(int i = 0; i<n-l; ++i){
                int j = i+l;
                dp[i][j] = INT_MAX;
                for(int k = i; k<j; ++k){
                    maxs[i][j] = max(maxs[i][k], maxs[k+1][j]);
                    dp[i][j] = min(maxs[i][k] * maxs[k+1][j] + dp[i][k] + dp[k+1][j], dp[i][j]) ;
                }
            }
        }
        for(int l = 1; l<n; ++l){
            for(int i = 0; i<n-l; ++i){
                int j = i+l;
                    cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<maxs[i][j]<<endl;
            }
        }
        return dp[0][n-1];
    }
};
int main(){
    Solution sol;
    vector<int> arr = {6, 2, 4};
    vector<int> arr1 = {3, 6, 4, 7};
    vector<int> arr2 = {3, 6, 4, 7, 2, 5};
    cout<<sol.mctFromLeafValues(arr)<<endl;
    cout<<sol.mctFromLeafValues(arr1)<<endl;
    return 0;
}
// @lc code=end

