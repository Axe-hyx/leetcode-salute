/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    // 可以改用dp, nx * nx *4, dp[][] new 

    // 类内空间和堆栈空间不一样，堆栈上可以用的空间更多
    // 这里的dp减小了空间，防止漏内存
    const static int nx = 200;
    double mem[nx][nx];
    double f(int a, int b){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0) return 1.0;
        if(b<=0) return 0.0;

        // double无法用equal直接判断，判断符号
        if(mem[a][b] > 0.0) return mem[a][b];
        mem[a][b] = 0.25 * (f(a-4, b) + f(a-3,b-1) + f(a-2, b-2)+ f(a-1, b-3));
        return mem[a][b];
    }
    double soupServings(int N) {
        if(N>= 4500) return 1.0;
        N = N % 25 ==0? N /25 : (N+24) / 25;
        return f(N, N);
    };
};
int main(){
    Solution sol;
    cout<<sol.soupServings(50)<<endl;
    cout<<sol.soupServings(1000)<<endl;
    cout<<sol.soupServings(660295675)<<endl;
    cout<<sol.soupServings(4801)<<endl;
    return 0;
}
// @lc code=end

