/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets;
        unordered_map<int, int> freq;
        int cnt = 0;
        for (auto i : nums) {
            freq[i]++;
            cnt = max(cnt, freq[i]);
        }
        buckets.resize(cnt, vector<int>());
        for (auto n = freq.begin(); n != freq.end(); ++n) {
            buckets[n->second-1].push_back(n->first);
        }

        vector<int> ans;
        for (int i = cnt - 1; i >= 0; --i) {
          for (auto n : buckets[i]) {
              ans.push_back(n);
              if(ans.size() == k) return ans;
          }
        }
        return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    {
      vector<int> nums{1, 1, 1, 2, 2, 3};
      for (auto i : sol.topKFrequent(nums, 2)) {
          cout<<i<<" ";
      }
      cout<<endl;
    }
    {
      vector<int> nums{-1, -1};
      for (auto i : sol.topKFrequent(nums, 1)) {
        cout << i << " ";
      }
      cout << endl;
    }
    return 0;
}
// @lc code=end
