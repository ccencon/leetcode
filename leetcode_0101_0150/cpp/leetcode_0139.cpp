/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int sl = s.size(), wdl = wordDict.size();
        vector<bool> dp(sl + 1, false); dp[0] = true;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        for(int i = 0; i < sl; i++){
            if(dp[i] && set.find(s.substr(i, 1)) != set.end())
                dp[i + 1] = true;
            else{
                for(int j = i - 1; j >= 0; j--)
                    if(dp[j] && set.find(s.substr(j, i - j + 1)) != set.end()){
                        dp[i + 1] = true;
                        break;
                    }
            }
        }
        return dp[sl];
    }
};
// @lc code=end

