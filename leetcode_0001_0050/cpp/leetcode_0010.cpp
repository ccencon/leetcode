/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
// class Solution {
// public:
//     bool isMatch(string s, string p) {//s可以为空，p不能为空
//         int sIdx = 0;
//         for(int i = 0; i < p.length(); i++){
//             if(i + 1 < p.length() && p[i + 1] == '*'){
//                 if(i + 2 < p.length()){//递归计算,直至找到最长匹配
//                     int matchIdx = -1;
//                     for(int tmpIdx = sIdx; tmpIdx <= s.length(); tmpIdx++){
//                         if(p[i] != '.' && tmpIdx != sIdx && s[tmpIdx - 1] != p[i])
//                             break;
//                         if(isMatch(s.substr(tmpIdx), p.substr(i + 2)))
//                             matchIdx = tmpIdx;
//                     }
//                     return matchIdx != -1;
//                 }
//                 if(p[i] == '.')
//                     sIdx = s.length();
//                 else
//                     while(sIdx < s.length() && s[sIdx] == p[i])
//                         sIdx++;
//                 i++;
//             }
//             else{
//                 if(sIdx >= s.length())
//                     return false;
//                 if(p[i] != '.' && s[sIdx] != p[i])
//                     return false;
//                 sIdx++;
//             }
//         }
//         return sIdx >= s.length();
//     }
// };
//DP
class Solution {
public:
    bool isMatch(string s, string p) {
        int sl = s.length(), pl = p.length();
        vector<vector<unsigned char>> dp(sl, vector<unsigned char>(pl));
        auto character_matcher = [&](int i, int j){
            if(i){
                if(j)
                    dp[i][j] = (p[j] == '.' || s[i] == p[j]) && dp[i - 1][j - 1];//迁移状态
                else
                    dp[i][0] = 0;//初始状态,i不为0且j为0时必为false
            }
            else{
                if(j){
                    if(dp[0][j] = (p[j] == '.' || s[0] == p[j])){
                        int tmpJ = j - 1;
                        while(tmpJ >= 0){
                            if(p[tmpJ] != '*'){
                                dp[0][j] = 0;
                                break;
                            }
                            tmpJ -= 2;
                        }
                    }
                }
                else//初始状态
                    dp[0][0] = (p[0] == '.' || s[0] == p[0]);
            }
        };
        auto star_matcher = [&](int i, int j){//j大于等于1
            dp[i][j] = j >= 2 && dp[i][j - 2];
            if(p[j - 1] == '.' || s[i] == p[j - 1])
                dp[i][j] |= ((i && dp[i - 1][j]) || (!i && dp[0][j - 1]));
        };
        auto matcher = [&](char c, int i, int j){
            if(c == '*')
                star_matcher(i, j);
            else
                character_matcher(i, j);
        };
        for(int i = 0; i < sl; i++)
            for(int j = 0; j < pl; j++)
                matcher(p[j], i, j);
        return dp[sl - 1][pl - 1];
    }
};
// @lc code=end

