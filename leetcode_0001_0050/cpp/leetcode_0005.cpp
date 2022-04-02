/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        int beginIdx = 0, endIdx = 0;
        for (int i = 0; i < (int)s.length(); i++){
            int bi = i - 1, ei = i + 1;
            while(bi >= 0 && ei < (int)s.length() && s[bi] == s[ei]){
                if (endIdx - beginIdx < ei - bi){
                    beginIdx = bi;
                    endIdx = ei;
                }
                bi--;
                ei++;
            }
            if(i - 1 >= 0 && s[i] == s[i - 1]){
                bi = i - 1, ei = i;
                do{
                    if (endIdx - beginIdx < ei - bi){
                        beginIdx = bi;
                        endIdx = ei;
                    }
                    bi--;
                    ei++;
                }while(bi >= 0 && ei < (int)s.length() && s[bi] == s[ei]);
            }
        }
        return s.substr(beginIdx, endIdx - beginIdx + 1);
    }
};
// @lc code=end

