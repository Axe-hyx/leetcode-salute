/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int len = 100;
    int dfs(const vector<int> &boxes, int dp[100][100][100],int l, int r, int k){
        if(l>r) return 0;
        if(dp[l][r][k] != 0) return dp[l][r][k];
        // 处理同样颜色,避免dfs
        while(r > l && boxes[r]==boxes[r-1]){
            ++k; --r;
        }
        // 只有一个的时候k为0
        // 这里不要写错成dfs (,,k),抛弃了右边，k=0
        dp[l][r][k] = dfs(boxes, dp, l, r-1, 0) + (k+1) * (k+1);
        // 考虑余下数组中所有可能出现转移的box
        for(int i = r-1; i>=l;i--){
            //只有同颜色才能构造更多的得分
            if(boxes[i]==boxes[r]){
                dp[l][r][k] = max(dp[l][r][k], dfs(boxes, dp, i+1, r-1, 0) + dfs(boxes, dp, l, i, k+1));
            }
        }
        return dp[l][r][k];
    }
    int removeBoxes(vector<int>& boxes) {
        // 对于i，可以删除，可以不删除
        // 不删除，则需要记录当前序列中和i同颜色的个数
        // dp[i,j,k],左边的数量
        int dp[100][100][100];
        memset(dp, 0, sizeof(int) * 100 * 100 * 100);
        int ans = dfs(boxes, dp, 0, boxes.size()-1, 0);
        return ans;

    }
};
int main(){
    Solution sol;
    vector<int> ve = {1,3,2,2,2,3,4,3,1};
    std::cout<<sol.removeBoxes(ve)<<endl;
    vector<int> ve1 = {3,4,3,3};
    std::cout<<sol.removeBoxes(ve1)<<endl;
    vector<int> ve2 = {1,2,3};
    std::cout<<sol.removeBoxes(ve2)<<endl;
    printf("%lld", 100 ^ 3);
    return 0;
    return 0;
}
// @lc code=end

