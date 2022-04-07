/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        static const unordered_map<char, int> _roman2Int_char = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000},
        };
        int ret = _roman2Int_char.at(s[0]);
        int last = ret;
        for(int i = 1; i < s.length(); i++){
            auto val = _roman2Int_char.at(s[i]);
            ret += val;
            if(val > last)
                ret -= 2 * last;
            last = val;
        }
        return ret;
    }
};
// @lc code=end

