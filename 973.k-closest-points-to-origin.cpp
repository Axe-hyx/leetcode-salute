/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "helper.h"
#endif
// Time Complexity:
// Space Complexity:
class Solution {
public:
  struct Pos {
    int dist;
    int i;
  };
  void swapPos(vector<Pos> &pos, int i, int j) {
    Pos tmp = pos[i];
    pos[i] = pos[j];
    pos[j] = tmp;
  }

  int kth(vector<Pos> &nums, int low, int high) {
    int pivot = nums[low].dist;
    int l = low, r = high + 1;

    while (l <= r) {
      while (l < high && nums[++l].dist <= pivot)
        ;
      while (r > low && nums[--r].dist >= pivot)
        ;

      if (l >= r)
        break;
      // l, r
      swapPos(nums, l, r);
    }
    // r, low
    swapPos(nums, r, low);
    return r;
  }
  vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {
    vector<vector<int>> ans;
    vector<Pos> dist;
    for (int i = 0; i < points.size(); ++i) {
      auto &vertex = points[i];
      dist.push_back({vertex[0] * vertex[0] + vertex[1] * vertex[1], i});
    }
    int p, l = 0, r = points.size() - 1;
    while (1) {
      p = kth(dist, l, r);
      if (p == K-1) {
        break;
      } else if (p < K) {
        l = p + 1;
      } else {
        r = p - 1;
      }
    }
    for (int i = 0; i < K; ++i) {
      ans.push_back(points[dist[i].i]);
    }
    return ans;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  {
    vector<vector<int>> nums{{1, 3}, {-2, 2}};
    help(sol.kClosest(nums, 1));
  }
  {
    vector<vector<int>> nums{{3, 3}, {5, -1}, {-2, 4}};
    help(sol.kClosest(nums, 2));
  }
}
// @lc code=end
