/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    struct node{
        int low, high, cnt;
        node():cnt(0){}
    };
    node *tree;
    int n;
    void build(int l, int r, const vector<int> &nums, int id = 1){
        if(l == r){
            tree[id].high = tree[id].low = nums[l];
            return;
        }
        int mid = l + ((r-l)>>1);
        tree[id].low = nums[l];
        tree[id].high = nums[r];
        build(l, mid, nums, id<<1);
        build(mid+1, r, nums, (id<<1)| 1 );
    }
    int query(int s, int t, int id, int l, int r){
        if(s<=tree[id].low && t >= tree[id].high) return tree[id].cnt;
        if(t < tree[id].low || s > tree[id].high){return 0;}
        int mid = l + ((r-l)>>1);
        return query(s, t, id<<1, l, mid) + query(s, t, (id<<1)+ 1, mid + 1, r);
    }
    void update(int v, int id = 1){
        tree[id].cnt++;
        if(tree[id].low == tree[id].high) return ;
        if(v<=tree[id<<1].high){
            update(v, id<<1);
        }else{
            update(v, id<<1|1);
        }
    }
    void debug(int id = 1){
        printf("%d %d %d\n", tree[id].low, tree[id].high, tree[id].cnt);
        if(tree[id].low == tree[id].high) return;
        debug(id<<1);debug(id<<1|1);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ori = nums;
        vector<int> ans;
        n = nums.size();
        if(n==0) return ans;
        ans.resize(n);
        tree = new node[n<<1 + 1];
        sort(nums.begin(), nums.end());
        build(0, n-1, nums);
        for(int i = n-1; i>=0; --i){
            ans[i] = query(INT_MIN, ori[i] - 1, 1, 0, n-1);
            update(ori[i]);
        }
        delete[] tree;
        return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    vector<int> nums = {5, 2, 6, 1};
    vector<int> nums1 = {};
    vector<int> nums2 = {1,9,7,8,5};
    vector<int> nums3 = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    sol.countSmaller(nums3);
    return 0;
}
// @lc code=end

