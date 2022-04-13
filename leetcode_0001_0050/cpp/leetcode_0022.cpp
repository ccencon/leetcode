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
                    tmp[traceIdx] = '(';//优先输入')'
                    left_count--;
                }
                else
                    tmp[traceIdx] = ')';
            }
            ret.push_back(tmp);
            while(--traceIdx >= 1)
                if(tmp[traceIdx] == '('){
                    left_count++;
                    if(2 * left_count <= sl - 1 - traceIdx){
                        tmp[traceIdx++] = ')';
                        break;
                    }
                }
        }
        return ret;
    }
};
// @lc code=end

