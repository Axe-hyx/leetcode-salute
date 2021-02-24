/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "helper.h"
#endif
// Time Complexity: O()
// Space Complexity: O()
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
  int guessNumber(int n) {
    int l = 1, r = n;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (guess(mid) == -1) {
          r =  mid -1;
      } else if (guess(mid) == 0) {
        return mid;
      } else
          l = mid + 1;
    }
    return r;
  }
};
int main(int argc, char **argv) {
  Solution sol;
  { sol.guessNumber(10); }
  return 0;
}
// @lc code=end
