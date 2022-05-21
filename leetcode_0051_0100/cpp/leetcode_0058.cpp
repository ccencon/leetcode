/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1, count = 1;
        for(; i >= 0; i--)
            if(s[i] != ' ')
                break;
        while(i >= 1 && s[--i] != ' ')
            count++;
        return count;
    }
};
// @lc code=end

