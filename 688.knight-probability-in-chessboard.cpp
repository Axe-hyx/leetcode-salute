/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity: N **2 * 8 * K
// Space Complexity:
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        double dp[K+1][N][N];
        memset(dp, 0, sizeof(double)*(K+1)*N*N);
        dp[0][r][c] = 1;
        int off_x[] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int off_y[] = {1, 2, 2, 1, -1, -2, -2, -1};
        for(int k = 1; k<=K; ++k){
            for(int i = 0; i<N; ++i){
                for(int j = 0; j<N; ++j){
                    for(int it = 0; it <8;++it){
                        int x = off_x[it] + i;
                        int y = off_y[it] + j;
                        if(x >=0 && x<N && y>=0 && y<N){
                            dp[k][i][j] += dp[k-1][x][y];
                        }
                    }
                    //cout<<dp[k][i][j]<<" ";
                }
                //cout<<endl;
            }
            //cout<<endl;
        }
        double sum = 0;
        for(int i = 0; i<N; ++i){
            for(int j = 0; j<N; ++j){
                sum+=dp[K][i][j];
            }
        }
        return (double)sum / (pow(8, K));

    }
};
int main(){
    Solution sol;
    cout<<sol.knightProbability(3, 2, 0, 0);
    cout<<sol.knightProbability(8, 30, 0, 0);
    return 0;
}
// @lc code=end

