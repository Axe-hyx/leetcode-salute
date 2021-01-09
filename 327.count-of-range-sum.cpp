/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int n;
    int d[2000];
    long long *presum;
    unordered_map<long long, int> map;
    struct node{
        long long low, high;
        int cnt;
        node():cnt(0){}
    };
    struct node *tree;

    // 递归建树和直接建树数据排列不一样
    void build(int l, int r, int id=1){
        if(l == r){
            tree[id].low = presum[l];
            tree[id].high = presum[l];
            return;
        }
        int mid = l + ((r-l) >>1);
        build(l, mid, id << 1);
        build(mid+1, r, id<<1 | 1);
        tree[id].low = presum[l];
        tree[id].high = presum[r];
    }
    int query(long long low, long long high, int id=1){
        if(high < tree[id].low || low > tree[id].high){ return 0;}
        if(low<=tree[id].low && high>=tree[id].high){
            return tree[id].cnt;
        }
        return query(low, high, id<<1) + query(low, high, id<<1|1);
    }
    void modify(long long v, int id=1){
        if(v>=tree[id].low && v<=tree[id].high){
            tree[id].cnt++;
        }
        if(tree[id].low == tree[id].high){return;}
        if(v<=tree[id<<1].high){
            modify(v, id<<1);
        }else{
            modify(v, id<<1|1);
        }
    }
    void debug(int id = 1){
        printf("%d %lld %lld %d\n", id, tree[id].low, tree[id].high, tree[id].cnt);
        if(tree[id].low == tree[id].high) return;
        debug(id<<1);
        debug(id<<1|1);
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        n = nums.size();
        presum = new long long[n+1];
        vector<long long> ori;
        presum[0] = 0;
        ori.push_back(0);
        for(int i = 1; i<=n; ++i){
            presum[i] = presum[i-1] + nums[i-1];
            ori.push_back(presum[i]);
        }
        sort(presum, presum + n+1);
        set<long long> st;
        for(int i = 0;i<=n;++i){
            st.insert(presum[i]);
            st.insert((long long)presum[i] - lower);
            st.insert((long long)presum[i] - upper);
        }
        map.clear();
        int p = 0;
        for(auto x : st){
            map[x] = p++;
            //printf("%lld %d\n", x, p);
        }
        tree = new node[(n+1)<<2];
        build(0, n);
        int ans = 0;
        for(auto x: ori){
            int tmp = query((long long)x - upper, (long long)x - lower);

            ans += tmp;
            modify(x);
        }
        delete[] presum;
        delete[] tree;
        return ans;
    }
};
int main(int argc, char **argv){
    Solution sol;
    vector<int> num = {-2, 5, -1};
    //cout<<sol.countRangeSum(num, -2, 2)<<endl;
    vector<int> num1 = {};
    //cout<<sol.countRangeSum(num, 0, 0)<<endl;
    vector<int> num2 = {0,-3,-3,1,1,2};
    //cout<<sol.countRangeSum(num2, 3, 5)<<endl;
    vector<int> num3 = {-1, 1};
    //cout<<sol.countRangeSum(num3, 0, 0)<<endl;
    vector<int> num4 = {2147483647,-2147483648,-1,0};
    //cout<<sol.countRangeSum(num4, -1, 0)<<endl;
    vector<int> num5 = {-2147483647,0,-2147483647,2147483647};
    cout<<sol.countRangeSum(num5, -564, 3864)<<endl;
    return 0;
}
// @lc code=end

