/*
 * @lc app=leetcode.cn id=159 lang=cpp
 *
 * [159] 至多包含两个不同字符的最长子串
 */

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.size() == 0)
            return 0;
        int maxl = 1, index = 1, ret = 1;
        char c1 = s[0], c2;
        vector<int> lens(s.size(), 1);
        for(; index < s.size() && s[index] == c1; index++)
            lens[index] = ++maxl;
        if(index == s.size())
            return index;
        c2 = s[index];
        for(; index < s.size(); index++){
            if(s[index] == c1 || s[index] == c2){
                ret = max(++maxl, ret);
                if(s[index] == s[index - 1])
                    lens[index] = lens[index - 1] + 1;
            }
            else{
                maxl = lens[index - 1] + 1;
                if(s[index - 1] == c1)
                    c2 = s[index];
                else
                    c1 = s[index];
            }
        }
        return ret;
    }
};
// @lc code=end

