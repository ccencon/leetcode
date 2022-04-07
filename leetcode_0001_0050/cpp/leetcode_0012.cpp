/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string ret;
        auto trans_4_5_9 = [&](int factor, char h, char m, char l){
            if(num >= 9 * factor){
                num -= 9 * factor;
                ret += l;
                ret += h;
            }
            else if(num >= 5 * factor){
                num -= 5 * factor;
                ret += m;
            }
            else if(num >= 4 * factor){
                num -= 4 * factor;
                ret += l;
                ret += m;
            }
        };
        auto trans_1 = [&](int factor, char h){
            while(num >= factor){
                num -= factor;
                ret += h;
            }
        };
        trans_1(1000, 'M');
        trans_4_5_9(100, 'M', 'D', 'C');
        trans_1(100, 'C');
        trans_4_5_9(10, 'C', 'L', 'X');
        trans_1(10, 'X');
        trans_4_5_9(1, 'X', 'V', 'I');
        trans_1(1, 'I');
        return ret;
    }
};
// @lc code=end

