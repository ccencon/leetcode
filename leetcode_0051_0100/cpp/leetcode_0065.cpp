/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        bool eE = false, prevNumber = false;
        function<bool(int)> isValidInteger = [&](int index){
            for(; index < s.length(); index++){
                if(s[index] == 'e' || s[index] == 'E'){
                    if(eE || !prevNumber)
                        return false;
                    if(index + 1 == s.length())
                        return false;
                    eE = true;
                    if(s[index + 1] == '+' || s[index + 1] == '-'){
                        if(index + 2 == s.length())
                            return false;
                        return isValidInteger(index + 2);
                    }
                    return isValidInteger(index + 1);
                }
                if(s[index] < '0' || s[index] > '9')
                    return false;
                prevNumber = true;
            }
            return true;
        };
        int pos = 0;
        if(s[pos] == '+' || s[pos] == '-')
            pos++;
        for(; pos < s.length(); pos++){
            if(s[pos] == '.'){
                if(pos + 1 == s.length())
                    return prevNumber;
                return isValidInteger(pos + 1);
            }
            if(s[pos] == 'e' || s[pos] == 'E')
                return isValidInteger(pos);
            if(s[pos] < '0' || s[pos] > '9')
                return false;
            prevNumber = true;
        }
        return true;
    }
};
// @lc code=end

