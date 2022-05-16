/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();
        int sl = s.length(), pl = p.length();
        vector<vector<int>> dp(pl);
        if(p[0] == '*')
            for(int j = 0; j <= sl; j++)
                dp[0].push_back(j);
        else if(p[0] == '?' || s[0] == p[0])
            dp[0].push_back(1);
        for(int i = 1; i < pl; i++){
            auto& prev = dp[i - 1];
            if(prev.empty())
                break;
            if(p[i] == '*')
                for(int j = prev[0]; j <= sl; j++)
                    dp[i].push_back(j);
            else
                for(auto j : prev){
                    if(j == sl)
                        break;
                    if(p[i] == '?' || p[i] == s[j])
                        dp[i].push_back(j + 1);
                }
        }
        auto& vec = dp[pl - 1];
        return !vec.empty() && vec[vec.size() - 1] == sl;
    }
};
// @lc code=end

