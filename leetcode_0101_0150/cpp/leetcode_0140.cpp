/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>
#include <functional>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int sl = s.size(), wdl = wordDict.size();
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<vector<int>> mem_dict(sl, vector<int>(sl + 1, -1));
        vector<int> mem_access(sl, -1);
        vector<string> ans; string sub;
        function<void(int)> helper = [&](int idx){
            if(idx >= sl){
                sub.resize(sub.size() - 1);
                ans.emplace_back(sub);
                return;
            }
            if(mem_access[idx] == 0)
                return;
            size_t _s = ans.size();
            for(int length = 1; idx + length <= sl; length++){
                if(mem_dict[idx][length] == -1)
                    mem_dict[idx][length] = set.find(s.substr(idx, length)) == set.end() ? 0 : 1;
                if(mem_dict[idx][length] == 0)
                    continue;
                size_t size = sub.size();
                sub += s.substr(idx, length) + " ";
                helper(idx + length);
                sub.resize(size);
            }
            mem_access[idx] = _s == ans.size() ? 0 : 1;
        };
        helper(0);
        return ans;
    }
};
// @lc code=end

