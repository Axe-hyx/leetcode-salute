/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
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
        int ans = 0;
        for(int i = 0, j = 0; ;){
            while(i+1<n && prices[i+1] < prices[i]){
                ++i;
            }
            j = i+1;
            while(j+1 < n && prices[j+1] > prices[j]){
                ++j;
            }
            if(i < n && j < n){
                ans += prices[j] - prices[i];
            }else
                break;
            i = j+1;
        }
        return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    vector<int> prices {7, 1, 5, 3, 6, 4};
    cout<<sol.maxProfit(prices)<<endl;
    vector<int> prices1 {1, 2, 3, 4, 5};
    cout<<sol.maxProfit(prices1)<<endl;
    vector<int> prices2 {7, 6, 4, 3, 1};
    cout<<sol.maxProfit(prices2)<<endl;
    return 0;
}
// @lc code=end
