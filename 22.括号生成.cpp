/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int left_count = n - 1, traceIdx = 1, sl = 2 * n;
        vector<string> ret;
        string tmp(sl, '(');
        while(traceIdx >= 1){
            for(; traceIdx < sl; traceIdx++){
                if(left_count > 0){
                    tmp[traceIdx] = '(';
                    left_count--;
                }
                else
                    tmp[traceIdx] = ')';
            }
            ret.push_back(tmp);
            
        }
        return ret;
    }
};
// @lc code=end

