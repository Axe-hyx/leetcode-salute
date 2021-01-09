/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int clist[128];
        memset(clist, -1, sizeof(int) * 128);
        int n = s.size();
        int ans = 0;
        deque<int> substr;
        for(int i = 0; i < n; ++i){
            substr.push_back(i);
            while(!substr.empty() && substr.front() <= clist[s[i] - ' ']){
                substr.pop_front();
            }
            clist[s[i] - ' '] = i;
            ans = max(ans, (int)substr.size());
        }
        return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    string s = "abcabcbb";
    cout<<sol.lengthOfLongestSubstring(s)<<endl;
    string s1 = "bbbbb";
    cout<<sol.lengthOfLongestSubstring(s1)<<endl;
    string s2 = "pwwkew";
    cout<<sol.lengthOfLongestSubstring(s2)<<endl;
    string s3 = "";
    cout<<sol.lengthOfLongestSubstring(s3)<<endl;
    string s4 = " ";
    cout<<sol.lengthOfLongestSubstring(s4)<<endl;
    return 0;
}
// @lc code=end
