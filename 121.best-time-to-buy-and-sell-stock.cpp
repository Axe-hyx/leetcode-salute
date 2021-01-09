/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        int mp = prices[0];
        int ans = 0;
        for(int i = 0; i<n;++i){
            if(prices[i] > mp)
                 ans = max(prices[i] - mp, ans);
            mp = min(mp, prices[i]);
        }
        return ans;
        
    }
};
int main(){
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout<<sol.maxProfit(prices)<<endl;
    vector<int> prices1 = {7, 6, 4, 3, 1};
    cout<<sol.maxProfit(prices1)<<endl;
    return 0;
}
// @lc code=end

