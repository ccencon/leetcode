/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 颠倒字符串中的单词
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int sl = s.size(), left = 0, right = 0;
        while(right < sl){
            if(s[right] == ' '){
                right++;
                continue;
            }
            int idx = left;
            while(right < sl && s[right] != ' '){
                s[left++] = s[right++];
            }
            reverse(s.begin() + idx, s.begin() + left);
            s[left++] = ' ';
        }
        s.resize(left - 1);
        return s;
    }
};
// @lc code=end

