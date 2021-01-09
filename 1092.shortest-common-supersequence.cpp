/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
		int n = str1.size(), m = str2.size();
		int dp[n+1][m+1];
        memset(dp, 0, sizeof(int) * (n+1) * (m + 1));
		for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=m; ++j){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
		}
        string s = "";
        //注意for循环条件
        for(int i = n, j = m; !(i==0 && j==0);){
            if(i == 0){
                s += str2[j-1];
                j--;
                continue;
            }
            if( j == 0 ){
                s+= str1[i-1];
                i--;
                continue;
            }

            if(str1[i-1] != str2[j-1]){
                if(dp[i][j-1] >= dp[i-1][j]){
                    s += str2[j-1];
                    j--;
                }else{
                    s += str1[i-1];
                    i--;
                }
            }else{
                s += str1[i-1];
                i--, j--;
            }
        }
        reverse(s.begin(), s.end());
        return s;
        /*
           int n = str1.size(), m = str2.size();
           int dp[n+1][m+1];
           for(int i = 0; i<=n; ++i){
           dp[i][0] = i;
           }
           for(int i = 0; i<=m; ++i){
           dp[0][i] = i;
           }
           int last = 0;
           for(int i = 1; i<=n; ++i){
           for(int j = 1; j<=m; ++j){  
           if(str1[i-1] == str2[j-1]){
           dp[i][j] = dp[i-1][j-1];
           last = 3;
           }else{
           if(dp[i-1][j] <= dp[i][j-1]){
           dp[i][j] = dp[i-1][j] + 1;
           last = 1;
           }else{
           dp[i][j] = dp[i][j-1] + 1;
           last = 2;
           }
           }
           }
           }   
           for(int i = 0; i<=n; ++i){
           for(int j = 0; j<=m; ++j){  
           printf("%d ", dp[i][j]);
           }
           printf("\n");
           }
           string s= "";
           int i = n, j = m;
           while(i !=0 && j != 0){
           printf("%d %d\n", i, j);
           if(str1[i-1] != str2[j-1]){
           if(dp[i][j-1] <= dp[i-1][j]){ // a < d
           s+=str2[j-1];
           j--;
           }else{
           s+=str1[i-1];
           i--;
           }
           }else{
           s+=str1[i-1];
           i--, j--;
           }
           }
           if(last == 1){
           }else if(last == 2){
           }
           reverse(s.begin(), s.end());
           return s;
           */
    }
};

int main(){
    Solution sol;
    string s1 = "abc", t1 = "abac";
    cout<<sol.shortestCommonSupersequence(s1, t1)<<endl;
    string s2 = "abac", t2 = "cab";
    cout<<sol.shortestCommonSupersequence(s2, t2)<<endl;
    string s3 = "bbbaaaba", t3 = "bbababbb";
    cout<<sol.shortestCommonSupersequence(s3, t3)<<endl;
    return 0;
}
// @lc code=end

