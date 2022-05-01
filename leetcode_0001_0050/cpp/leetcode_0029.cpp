/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include <climits>
// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN){
            if(divisor == 1)
                return INT_MIN;
            if(divisor == -1)
                return INT_MAX;
        }
        if(divisor == INT_MIN)
            return dividend == INT_MIN ? 1 : 0;
        int factor = 1, quotient = 0;
        if(dividend > 0){
            factor = -1;
            dividend = -dividend;
        }
        if(divisor > 0){
            factor *= -1;
            divisor = -divisor;
        }
        if(dividend == INT_MIN){//处理一下溢出问题，使dividend可以顺利移位
            quotient++;
            dividend -= divisor;
        }
        for(int i = 31; i >= 0; i--){
            if(-(-dividend >> i) <= divisor){
                quotient += 1 << i;
                dividend -= -(-divisor << i);
            }
        }
        return factor * quotient;
    }
};
// @lc code=end

