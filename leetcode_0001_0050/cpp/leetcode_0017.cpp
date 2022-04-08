/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        static const unordered_map<int, string> num2chars = {
            {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"},
            {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
        };
        if(digits.empty())
            return {};
        vector<string> ret;
        vector<int> idxRec(digits.size(), 0);
        int traceIdx = 0;
        string tmp(digits.size(), 0);
        while(traceIdx >= 0){
            for(; traceIdx < digits.size(); ++traceIdx)
                tmp[traceIdx] = num2chars.at(digits[traceIdx]-'0')[idxRec[traceIdx]++];
            ret.push_back(tmp);
            while(--traceIdx >= 0 && idxRec[traceIdx] >= num2chars.at(digits[traceIdx]-'0').size())
                idxRec[traceIdx] = 0;
        }
        return ret;
    }
};
// @lc code=end

