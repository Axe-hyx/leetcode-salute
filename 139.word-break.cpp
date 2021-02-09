/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> sets;
        for(auto s: wordDict){
            sets.insert(s);
        }
        int n = s.size();
        bool dp[n+1];
        memset(dp, false ,(n+1) * sizeof(bool));
        dp[0] = true;
        //dp
        for(int i = 1; i<=n; ++i){
            for(int j = 0; j<i; ++j){
                if(dp[j] && sets.find(s.substr(j, i-j)) != sets.end()){
                    dp[i] = true;
                }
            }
        }
        return dp[n];
    }
};
int main(int argc, char **argv){
    Solution sol;
    {
        string str {"leetcode"};
        vector<string> strings {"leet", "code"};
        cout<<sol.wordBreak(str, strings)<<endl;
    }
    {
        string str {"applepenapple"};
        vector<string> strings {"apple", "pen"};
        cout<<sol.wordBreak(str, strings)<<endl;
    }
    {
        string str {"catsandog"};
        vector<string> strings {"cats", "dog", "sand", "and"};
        cout<<sol.wordBreak(str, strings)<<endl;
    }
    return 0;
}
// @lc code=end
