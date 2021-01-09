/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int ans = 0;
        for(int i = 0, j=0; i<s.size() && j < g.size(); ++j){
            if(s[i] >= g[j]){
                ++i;
                ++ans;
            }
        }
        return ans;
    }
    
};
int main(int argc, char **argv){
    Solution sol;
    vector<int> g = {1,2,3}, s = {1, 1};
    cout<<sol.findContentChildren(g, s)<<endl;
    vector<int> g1 = {1,2}, s1 = {1, 2, 3};
    cout<<sol.findContentChildren(g1, s1)<<endl;
    return 0;
}
// @lc code=end
