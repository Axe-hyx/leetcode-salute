/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
    public:
        void combine(vector<vector<int>> &ans, int target, int sum, int idx, vector<bool> & has,
                const vector<int> & candidates){
            if(idx == -1){
                if(target == sum){
                    vector<int> tmp;
                    for(int i = 0; i < has.size(); ++i){
                        if(has[i])
                            tmp.push_back(candidates[i]);
                    }
                    ans.push_back(tmp);
                }
                return;
            }
            if(sum > target){
                return;
            }
            int cur = sum;
            combine(ans, target, cur, idx-1, has, candidates);
            if(idx != candidates.size() -1 && candidates[idx] == candidates[idx+1] && !has[idx+1])
                return;
            has[idx] = true;
            cur+= candidates[idx];
            combine(ans, target, cur, idx-1, has, candidates);
            has[idx] = false;
        }

        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            vector<bool> has(candidates.size(), false);
            combine(ans, target, 0, candidates.size() - 1, has, candidates);
            return ans;

        }
};
int main(int argc, char **argv){
    Solution sol;
    {
        vector<int> candidates {10,1,2,7,6,1,5};
        int target = 8;
        auto ans = 
            sol.combinationSum2(candidates, target);
        for(auto vec : ans){
            for(auto v : vec){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    {
        vector<int> candidates {2, 5, 2, 1, 2};
        int target = 5;
        auto ans = 
            sol.combinationSum2(candidates, target);
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
