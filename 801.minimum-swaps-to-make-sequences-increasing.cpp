/*
 * @lc app=leetcode id=801 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int swap[n], not_swap[n];
        // 注意题目条件，交换的都是i位置处的元素
        swap[0] = 1; not_swap[0] = 0;

        for(int i = 1;i<n;++i){
            swap[i] = i+1, not_swap[i] = i+1;
            if(A[i-1] < A[i] && B[i-1] < B[i]){
                swap[i] = swap[i-1] + 1;
                not_swap[i] = not_swap[i-1];
            }
            if(A[i-1] < B[i] && B[i-1] < A[i]){
                swap[i] = min(not_swap[i-1] + 1, swap[i]);
                // 这里没交换，min(swap, ...)
                not_swap[i] = min(swap[i-1], not_swap[i]);
            }
        }
        return min(not_swap[n-1], swap[n-1]);
    }
};
int main(){
    Solution sol;
    vector<int> A={1,3,5,4}, B={1,2,3,7};
    cout<<sol.minSwap(A, B)<<endl;
    vector<int> A1={0,4,4,5,9}, B1={0,1,6,8,10};
    cout<<sol.minSwap(A1, B1)<<endl;
    return 0;
}
// @lc code=end

