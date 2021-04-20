/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include <bits/stdc++.h>
#include <doctest/doctest.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    bool substrMatch(const string &s, const string &p, int i, int j){
        if( i == s.size() && j == p.size()) return true;
        if(i>s.size() || j >= p.size()) return false;
        if(j+1 != p.size() && p[j+1] == '*'){
            if(p[j] == '.'){ // .*
                if(j +2 == p.size()){
                    return true;
                }else{
                    // 
                    while(i <= s.size()){
                        if(substrMatch(s, p, i, j+2)) return true;
                        ++i;
                    }
                    return false;
                }
            }
            // a*
            if( substrMatch(s, p, i, j+2)) return true;
            while(i != s.size() && s[i] == p[j]){
                if( substrMatch(s, p, i+1, j+2)) return true;
                i++;
            }
            return false;
        }else{
            if(p[j] == '.'){
                return substrMatch(s, p, i+1, j+1);
            }else{
                if(p[j] == s[i]){
                    return substrMatch(s, p, i+1, j+1);
                }else{
                    return false;
                }
            }
        }
    }
    bool isMatch(string s, string p) {
        return substrMatch(s, p, 0, 0);
    }
};
int main(int argc, char **argv){
    Solution sol;
      cout<<sol.isMatch("aa", "a")<<endl; // 0
      cout<<sol.isMatch("aa", "a*")<<endl; // 1
      cout<<sol.isMatch("ab", ".*")<<endl; // 1
      cout<<sol.isMatch("a", "c*a")<<endl; // 1
      cout<<sol.isMatch("aab", "c*a*b")<<endl; // 1
      cout<<sol.isMatch("mississippi", "mis*is*p*.") <<endl; // 0
      cout<<sol.isMatch("ab", ".*c") <<endl; // 0
      cout<<sol.isMatch("a", "a*a") <<endl; // 0
      cout<<sol.isMatch("bbbba", ".*a*a") <<endl; // 1
      cout<<sol.isMatch("b", "b.*c") <<endl; // 0
      cout<<sol.isMatch("ab", ".*..") <<endl; // 0
      cout<<sol.isMatch("", "..*") <<endl; // 0
      cout<<sol.isMatch("bbabacccbcbbcaaab",
      "a*b*a*a*c*aa*c*bc*")<<endl; // 0
      cout<<sol.isMatch("aa",
      "a*")<<endl; // 0
    cout<<sol.isMatch("aabcbcbcaccbcaabc", ".*a*aa*.*b*.c*.*a*")<<endl;
    return 0;
}
// @lc code=end
