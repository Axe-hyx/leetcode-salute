/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#include "helper.h"
#endif
// Time Complexity: O()
// Space Complexity: O()
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if(!isBadVersion(mid)) start = mid+1;
            else end = mid;
        }
        return end;
    }
};
int main(int argc, char **argv){
    Solution sol;
    {
        help(sol.firstBadVersion(5));
    }
    return 0;
}
// @lc code=end
