/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <climits>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        while(idx < s.length() && s[idx] == ' ')
            idx++;
        if(idx >= s.length())
            return 0;
        long long factor = 1; 
        if(s[idx] == '-'){
            factor = -1;
            idx++;
        }
        else if(s[idx] == '+')
            idx++;
        long long ret = 0;
        while(idx < s.length() && s[idx] >= '0' && s[idx] <= '9'){
            ret = ret * 10 + factor * (s[idx] - '0');
            if(ret >= INT_MAX)
                return INT_MAX;
            if(ret <= INT_MIN)
                return INT_MIN;
            idx++;
        }
        return ret;
    }
};
// @lc code=end

