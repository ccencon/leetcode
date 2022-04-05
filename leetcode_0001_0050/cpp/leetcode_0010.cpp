/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {//s可以为空，p不能为空
        int sIdx = 0;
        for(int i = 0; i < p.length(); i++){
            if(i + 1 < p.length() && p[i + 1] == '*'){
                if(i + 2 < p.length()){//递归计算,直至找到最长匹配
                    int matchIdx = -1;
                    for(int tmpIdx = sIdx; tmpIdx <= s.length(); tmpIdx++){
                        if(p[i] != '.' && tmpIdx != sIdx && s[tmpIdx - 1] != p[i])
                            break;
                        if(isMatch(s.substr(tmpIdx), p.substr(i + 2)))
                            matchIdx = tmpIdx;
                    }
                    if(matchIdx == -1)
                        return false;
                    return true;
                }
                if(p[i] == '.')
                    sIdx = s.length();
                else
                    while(sIdx < s.length() && s[sIdx] == p[i])
                        sIdx++;
                i++;
            }
            else{
                if(sIdx >= s.length())
                    return false;
                if(p[i] != '.' && s[sIdx] != p[i])
                    return false;
                sIdx++;
            }
        }
        if(sIdx < s.length())
            return false;
        return true;
    }
};
// @lc code=end

