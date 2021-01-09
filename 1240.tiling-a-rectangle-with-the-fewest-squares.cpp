/*
 * @lc app=leetcode id=1240 lang=cpp
 *
 * [1240] Tiling a Rectangle with the Fewest Squares
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int tilingRectangle(int n, int m) {
        if(n < m) swap(n, m);
		// 初始化，leetcode不认 dp[][] = {} variable size object initilization
		int dp[n+1][m+1];
		memset(dp, 0, (m+1) * (n+1) * sizeof(int));
		for(int i = 1; i<=n;++i){
			for (int j = 1; j <= m; j++){
				if (i == j) {
					dp[i][j] = 1;
					continue;
				}
				dp[i][j] = i * j;
				for (int k = 1; k <= i / 2; k++)
					dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j]);
				// 循环条件手误 i/2
				for (int k = 1; k <= j / 2; k++)
					dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k]);
			}
		}
		int res(dp[n][m]);
		// heights, 初始值
		vector<int> heights(n, 0);
		dfs(n, m, heights,0, res);
		return res;
	}
	void dfs(const int n, const int m, vector<int> &heights, const int cnt, int &res){
		if(cnt >= res) return;

		int left = 0;
		int min_height = m;
		for(int i = 0; i<n; ++i){
			if(heights[i] < min_height){
				min_height = heights[left = i];
			}
		}
		if(min_height == m){
			// 漏掉条件
			res = min(res, cnt);
			return;
		}
		int right = left;
		while(right <n && heights[left] == heights[right] && right - left + min_height +1 <= m) ++right;

		for(int i = left; i < right; ++i){
			heights[i] += right - left;
		}
		for(int size = right - left; size >=1; --size){
			// dfs 提前，少一行代码
			dfs(n, m, heights, cnt+1, res);
			for(int i = left; i<left + size; ++i){
				heights[i]--;
			}
			// -= size -1 , not right -left backtracing，恢复现场
			
			heights[left+size-1] -= size -1;
		}
	}

};
// @lc code=end
int main(){
	Solution sol;
	cout<<sol.tilingRectangle(2, 3)<<endl;
	cout<<sol.tilingRectangle(5, 8)<<endl;
	cout<<sol.tilingRectangle(11, 13)<<endl;
	return 0;
}
