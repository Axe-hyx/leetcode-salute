/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
// Time Complexity:
// Space Complexity:
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(int) * (n+1) * (m+1));
        for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=m; ++j){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        for(int i = 1; i<=n; ++i){
            for(int j = 1; j<=m; ++j){
                if((dp[i][j] == j && s[i-1] == t[j-1])){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        long long presum[n+1];
        memset(presum, 0, sizeof(long long) * (n+1));
        for(int j = 1; j<=m; ++j){
            // multiple
            for(int i = 1; i<=n; ++i){
                dp[i][j] = (j == 1 ? 1 : presum[i-1]) * dp[i][j];
                cout<<dp[i][j]<<" ";
            }
            //acc
            for(int i = 1; i<=n; ++i){
                //might overflow 
                presum[i] = presum[i-1] + dp[i][j];
            }
            cout<<endl;
        }
        int ans = 0;
        for(int i = 1; i<=n; ++i){
            ans += dp[i][m];
        }
        return ans;

    }
};
int main(){
    Solution sol;
    string s1 = "rabbbit", t1 = "rabbit";
    cout<<sol.numDistinct(s1, t1)<<endl;
    string s2 = "babgbag", t2 = "bag";
    cout<<sol.numDistinct(s2, t2)<<endl;
    string s3 = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo", t3 = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    cout<<sol.numDistinct(s3, t3)<<endl;
    return 0;
}
// @lc code=end

