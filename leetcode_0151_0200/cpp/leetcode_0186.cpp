/*
 * @lc app=leetcode.cn id=186 lang=cpp
 *
 * [186] 反转字符串中的单词 II
 */

// @lc code=start
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        s.emplace_back(' ');
        int left = 0, right = 0;
        while(right < s.size()){
            if(s[right] != ' '){
                right++;
                continue;
            }
            reverse(s.begin() + left, s.begin() + right);
            left = ++right;
        }
        s.resize(s.size() - 1);
    }
};
// @lc code=end

