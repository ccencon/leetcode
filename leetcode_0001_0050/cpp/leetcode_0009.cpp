/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x > 9 && x % 10 == 0))//1121100
            return false;
        int num = 0;
        while(x > num){
            num = num * 10 + x % 10;
            x /= 10;
        }
        return x == num || x == num / 10;
    }
};
// @lc code=end

