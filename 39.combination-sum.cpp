/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    void combine(vector<vector<int>> &ans, int target, int sum, int idx, vector<int> & tmp,
            const vector<int> & candidates){
        if(idx == -1){
            if(target == sum){
                ans.push_back(tmp);
            }
            return;
        }
        if(sum > target){
            return;
        }
        int cur = sum;
        int cnt = 0;
        while(cur <= target){
            combine(ans, target, cur, idx-1, tmp, candidates);
            tmp.push_back(candidates[idx]);
            cur+= candidates[idx];
            ++cnt;
        }
        for(int i = 0; i<cnt; ++i){
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        combine(ans, target, 0, candidates.size() - 1, tmp, candidates);
        return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    {
        vector<int> candidates {2, 3, 6, 7};
        int target = 7;
        auto ans = 
            sol.combinationSum(candidates, target);
        for(auto vec : ans){
            for(auto v : vec){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// @lc code=end
