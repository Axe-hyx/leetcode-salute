/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int dp[50][50];
        memset(dp, 0, sizeof(int) * 50 * 50);
        int n = A.size();
        for(int d = 2; d < n; ++d){
            for(int l = 0;l < n; ++l){
                int r = l + d < n ? l+d:n-1;
                for(int x = l+1; x < r; ++x){
                    dp[l][r] = min(dp[l][r] == 0 ? INT_MAX : dp[l][r], 
                            dp[l][x] +  dp[x][r] + A[l] * A[r] * A[x]);
                }
            }
        }
        // 考虑i，j为固定边，每出一条边少一对i，j

        // i (n-1, 0, --)
        // j (i+1, n-1, ++)
        // k (i+1, j, ++) 先生成右边，再左边
        return dp[0][n-1];
    }    
};
int main(){
    Solution sol;
    std::vector<int> A = {3, 7, 4, 5};
    std::cout<<sol.minScoreTriangulation(A)<<std::endl;
    std::vector<int> A1 = {3, 7, 5};
    std::cout<<sol.minScoreTriangulation(A1)<<std::endl;
    std::vector<int> A2 = {1,3,1,4,1,5};
    std::cout<<sol.minScoreTriangulation(A2)<<std::endl;
    return 0;
}
// @lc code=end

