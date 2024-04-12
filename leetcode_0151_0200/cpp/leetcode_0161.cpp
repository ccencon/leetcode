/*
 * @lc app=leetcode.cn id=161 lang=cpp
 *
 * [161] 相隔为 1 的编辑距离
 */

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        function<bool(int, int)> ss_cmp = [&s, &t](int ls, int lt){
            for(; ls < s.size() && lt < t.size(); ls++, lt++){
                if(s[ls] != t[lt])
                    return false;
            }
            return ls == s.size() && lt == t.size();
        };
        int sl = s.size(), tl = t.size(), index = 0;
        if(abs(sl - tl) > 1)
            return false;
        for(; index < sl && index < tl; index++)
            if(s[index] != t[index])
                break;
        if(index == sl && index == tl)
            return false;
        //下面3个调用可以通过s和t的长度差进行优化，这里就懒得优化了
        return ss_cmp(index + 1, index + 1) || ss_cmp(index, index + 1) || ss_cmp(index + 1, index);
    }
};
// @lc code=end

