/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
  void visit(string start) {
    while (targets[start].size()) {
      string next = *targets[start].begin();
      targets[start].erase(targets[start].begin());
      visit(next);
    }
    ans.push_back(start);
  }

  map<string, multiset<string>> targets;
  vector<string> ans;
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    ans.clear();
    targets.clear();
    for (auto s : tickets) {
      targets[*s.begin()].insert(*(s.end() - 1));
    }
    visit("JFK");
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    vector<vector<string>> tickets{
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    for (auto s : sol.findItinerary(tickets)) {
      cout << s << " ";
    }
    cout << endl;
    {
      vector<vector<string>> tickets{{"JFK", "SFO"},
                                     {"JFK", "ATL"},
                                     {"SFO", "ATL"},
                                     {"ATL", "JFK"},
                                     {"ATL", "SFO"}};
      for (auto s : sol.findItinerary(tickets)) {
        cout << s << " ";
      }
      cout << endl;
    }
  }
}
// @lc code=end
