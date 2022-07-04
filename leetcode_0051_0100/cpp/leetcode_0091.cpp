/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;
        int sl = s.size();
        vector<int> dp(sl + 1); dp[0] = 1; dp[1] = 1; dp[sl] = sl == 1 ? 1 : 0;
        for(int i = 2; i <= sl; i++){
            int c2 = s[i - 2] - '0';
            int c1 = s[i - 1] - '0';
            if(c1 == 0){
                if(c2 == 0 || c2 >= 3)
                    break;
                dp[i] = dp[i - 2];
            }
            else{
                dp[i] = dp[i - 1];
                if(c2 != 0 && c2 * 10 + c1 <= 26)
                    dp[i] += dp[i - 2];
            }
        }
        return dp[sl];
    }
};
// @lc code=end

