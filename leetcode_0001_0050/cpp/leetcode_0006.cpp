/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string ret;
        int step = (numRows - 1) * 2;
        for(int l = 1; l <= numRows; l++){
            int pos = l - 1;
            if(l == 1 || l == numRows)
                while(pos < s.length()){
                    ret.push_back(s[pos]);
                    pos += step;
                }
            else{
                int subStep = (numRows - l) * 2;
                while(pos < s.length()){
                    ret.push_back(s[pos]);
                    pos += subStep;
                    subStep = step - subStep;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

