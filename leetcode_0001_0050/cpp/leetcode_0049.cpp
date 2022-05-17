/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> idxRec;
        for(const auto& s : strs){
            auto _s = s;
            sort(_s.begin(), _s.end());
            auto it = idxRec.find(_s);
            if(it == idxRec.end()){
                ans.push_back({});
                int idx = ans.size() - 1;
                ans[idx].emplace_back(s);
                idxRec[_s] = idx;
            }
            else
                ans[it->second].emplace_back(s);
        }
        return ans;
    }
};
// @lc code=end

