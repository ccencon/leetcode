/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        string::size_type basisIdx = 0;
        unordered_map<unsigned char, __typeof(basisIdx)> record;
        for(__typeof(basisIdx) i = 0; i < s.length(); i++){
            auto it = record.find(s[i]);
            if(it == record.end())
                record[s[i]] = i;
            else{
                if(maxLength < record.size())
                    maxLength = record.size();
                for(auto j = basisIdx; j < it->second; j++)
                    record.erase(s[j]);
                basisIdx = it->second + 1;
                record[s[i]] = i;
            }
        }
        if(maxLength < record.size())
            maxLength = record.size();
        return maxLength;
    }
};
// @lc code=end

