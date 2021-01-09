/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {

        vector<int> res;
        res.resize(num+1);
        res[0]=0;
        for(int i = 0; i<=num;++i){
            if(i%2==1){
                res[i] = res[i-1] + 1;
            }else{
                // 个数一样多
                res[i] = res[i/2];
            }
        }
        /*
        int j = 1;
        for(int i = 0; i<=num; ++i){
            if(i == 0){
                res[i]= 0;
                continue;
            }
            if((i&j)!=0){
                j<<=1;
                res[i] = 1;
            }else{
                res[i] = res[i-(j>>1)] + 1;
            }
        }
        */
        return res;
    }
};
// @lc code=end

