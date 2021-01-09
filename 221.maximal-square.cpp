/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int m = matrix.size();
            if(m == 0) return 0;
            int n = matrix[0].size();
            if(n == 0) return 0;
            int dp[m][n];
            for(int i= 0; i<m; ++i){
                for(int k = 0; k<n;++k){
                    matrix[i][k] -='0';
                }
            }
            for(int i =0; i<n;++i){
                dp[0][i] = matrix[0][i];
            }
            for(int i =0; i<m;++i){
                dp[i][0] = matrix[i][0];
            }
            for(int i = 1; i<m; ++i){
                for(int k = 1; k<n; ++k){
                    if(matrix[i][k]!=0){
                        int mi = min(min(dp[i-1][k-1], dp[i-1][k]), dp[i][k-1]);
                        dp[i][k] = mi + 1;
                        /*
                        brupe force
                           bool pass = true;
                           int st = (int)sqrt(dp[i-1][k-1]);
                           for(int stt = st; st>0; --st){
                           pass = true;
                           for(int i1 = i; i1>=i-st; --i1){
                           for(int i2 = k; i2>=k-st; --i2){
                           if(matrix[i1][i2] == '0'){
                           pass = false;
                           break;
                           }
                           }
                           }
                           if(pass){
                           dp[i][k] = (st+1) * (st+1);
                           break;
                           }
                           }
                           if(st == 0)  dp[i][k] = matrix[i][k]-'0';
                           */

                    }else
                        dp[i][k] = 0;
                }
            }
            int ans = -1;
            for(int i = 0; i<m; ++i){
                for(int k = 0; k<n; ++k){
                    ans = max(ans, dp[i][k]);
                }
            }
            return ans * ans;

        }
};
// @lc code=end

int main(){
    Solution sol;
    vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<sol.maximalSquare(matrix);

    vector<vector<char>> matrix1 = {{'0','0','0','1'},{'1','1','0','1'},{'1','1','1','1'},{'0','1','1','1'},{'0','1','1','1'}};
    vector<vector<char>> martix2= {{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','0','0','1','1','1','1','1','1','1','1','0','0','1','1','1','0','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','0','1','0','1','1','1','1','1','1','0','1','1','0','1','1','0','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','0','1','1','0','1','0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','0','1','1','0','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0','1','1','0','0','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','0','1','1','0','1','0','1','1','1','1','1','1','1','1','1','1','1','0','1','0','1','1','1','1','1','1','0','1','1','1','1'},{'0','1','1','0','1','1','0','1','0','1','1','1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0','1','0','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','1','1','1','1','1','1','1','0','0','1','1','0','0','1','1','0','1','1','0','1','0','1','0','1'},{'1','1','1','1','0','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','0','1','1','1','1','0','1','0','1','1','0','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1','1'},{'1','1','1','0','1','1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1','1','1','0','0','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','1','1','0','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0','1','1'},{'1','1','1','1','1','0','0','1','1','1','1','1','1','1','1','0','1','0','1','1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','0','1','1','1','1','1','1','0','0','1','1','1','1','1'},{'1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0','1','1','1'},{'1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','0','1','1','1','1','1','0','0','1','0','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','1','1','1','1','1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','0','1','1','1','1','1','0','1','1','1','1','1','0','1','1','0','1','1'},{'1','1','0','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','0','1','0','1','1','1','0','0','1','1','1','1','1','1','1','1'},{'1','1','1','0','0','1','0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1','0','1','1','1','1','0','1','1','1','1','1','0','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','0','1','1','1','1','1','1','0','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},{'1','1','1','0','0','1','1','1','1','1','1','1','1','1','1','0','1','1','1','0','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','1','1','1','1','1','1','0','1','0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','0','1','1','1','1','1','1','1','1','1','0','1','1','1','0','1'},{'1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','0','1','1','1','0','1','1','0','1','1'},{'1','1','1','1','0','1','1','0','1','1','1','1','1','1','0','1','1','0','1','1','0','1','1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','0','0','0','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','0','1','1','1','1','1','1','1','1','1','1','0','1','0','1','0','1','1','0','1','1','1','1','1','1','1','1'},{'1','0','1','1','0','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','0','0','1','1'},{'1','0','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','0','1','1','1','1','1'},{'0','1','1','1','1','0','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','0','1','1','1','1','0','1','1','1','1','1','1','0','1','0','1','1','0','0','1','1','1','1','0','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','0','1','1','1','0'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','0','0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0','0','1','1','1','1'},{'1','1','0','1','1','0','1','1','1','1','1','1','0','1','0','1','1','1','1','1','0','1','1','1','1','1','1','1','1','0','0','1','1','1','0','1','0','1','0','0'},{'0','1','1','0','1','1','1','1','1','1','1','0','0','1','1','1','1','1','0','0','1','0','1','1','1','1','1','0','1','1','1','0','1','1','0','1','1','1','0','1'}};
    cout<<sol.maximalSquare(martix2);
    return 0;
}