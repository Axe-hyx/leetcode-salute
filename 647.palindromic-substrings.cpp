/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int countSubstrings(string s) {
        //dp weather is palindromic string
        int n = s.size();
        int dp[n][n];
        int res = 0;
        for(int l = 0; l<n; ++l){
            for(int i = 0; i<n-l; ++i){
                int j = i + l;
                // 只有两个元素和一个元素的时候直接跳过
                // 只有首尾相等，才产生回文
                dp[i][j] = s[i] == s[j] && (j-i + 1 < 3 || dp[i+1][j-1]);
                if(dp[i][j]) {
                    ++res;
                }
            }
        }
        return res;
    }
};
int main(){
    Solution sol;
    string s = "abc";
    std::cout<<sol.countSubstrings(s)<<std::endl;
    string s1 = "aaa";
    std::cout<<sol.countSubstrings(s1)<<std::endl;
    return 0;
}
// @lc code=end

