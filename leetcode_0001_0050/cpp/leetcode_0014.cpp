/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret(strs[0]);
        int minSize = strs[0].size();
        for(auto& s : strs){
            minSize = min((int)s.size(), minSize);
            for(int j = 0; j < minSize; j++)
                if(ret[j] != s[j])
                    minSize = j;
        }
        return ret.substr(0, minSize);
    }
};
// @lc code=end

