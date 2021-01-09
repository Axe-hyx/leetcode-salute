/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class NumArray {
public:
    struct node{
        int left, right, sum;
    };
    int n;
    node *tree;
    int *num;
    NumArray(vector<int>& nums) {
        n = nums.size();
        if(n==0) return;
        tree = new node[n<<2];
        num = nums.data();
        build(0, n-1, 1);
    }
    void build(int l, int r, int id){
        if(l == r){
            tree[id].left = l;
            tree[id].right = r;
            tree[id].sum = num[l];
            return;
        }
        int mid = l + ((r-l)>>1);
        build(l, mid, id<<1);
        build(mid+1, r, id<<1 | 1);
        tree[id].left = l; 
        tree[id].right = r; 
        tree[id].sum = tree[id<<1].sum + tree[id<<1|1].sum;
    }
    void modify(int i, int val, int id = 1){
        tree[id].sum += val - num[i];
        if(tree[id].left == tree[id].right) {
            tree[id].sum = val;
            return;
        }
        if(i <= tree[id<<1].right){
            modify(i, val, id<<1);
        }else{
            modify(i, val, id<<1|1);
        }
    }

    int query(int s, int t, int l, int r, int id = 1){
        if(s<=l && t >=r) return tree[id].sum;
        if(t<l || s>r){
            return 0;
        }
        int mid = l +((r-l) >> 1);
        return query(s, t, l, mid, id<<1) + query(s, t, mid + 1, r, id<<1|1);

    }
    void update(int i, int val) {
        modify(i, val);
        // 修改完数据结构要记得修改原数组，
        num[i] = val;
    }
    void debug(int id = 1){
        printf("%d %d\n",id, tree[id].sum);
        if(tree[id].left == tree[id].right){
            return;
        }
        debug(id<<1); debug(id<<1|1);
    }
    int sumRange(int i, int j) {
        return query(i, j, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
int main(int argc, char **argv){
    vector<int> nums = {1,3,5};
    NumArray* obj = new NumArray(nums);
    int param_2 = obj->sumRange(0,2);
    printf("%d\n", param_2);
    obj->update(1,2);
    int param_3 = obj->sumRange(0,2);
    printf("%d\n", param_3);
    delete(obj); // 9 8

    vector<int> nums1 = {};
    NumArray* obj1 = new NumArray(nums1);

    vector<int> nums2 = {9,-8};
    NumArray* obj2 = new NumArray(nums2);
    obj2->update(0,3);
    int param_4 = obj2->sumRange(1,1);
    printf("%d\n", param_4); // 0
    int param_5 = obj2->sumRange(0,1);
    printf("%d\n", param_5);
    obj2->update(1,-3);
    int param_6 = obj2->sumRange(0,1);
    printf("%d\n", param_6);
    delete(obj2);


    vector<int> nums3 = {7,2,7,2,0};
    NumArray* obj3 = new NumArray(nums3);
    obj3->update(4, 6);
    obj3->update(0, 2);
    obj3->update(0, 9);
    cout<<obj3->sumRange(4, 4)<<endl; //6
    obj3->update(3, 8);
    cout<<obj3->sumRange(0, 4)<<endl;
    obj3->update(4, 1);
    cout<<obj3->sumRange(0, 3)<<endl;
    cout<<obj3->sumRange(0, 4)<<endl;
    return 0;
}
// @lc code=end
