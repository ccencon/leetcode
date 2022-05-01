/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordsMap, usedMap;
        for(const auto& p : words)
            wordsMap[p]++;
        int sLen = s.size(), wordLen = words[0].size(), wordsCount = words.size();
        for(int i = 0; i < wordLen; i++){
            int left = 0, right = 0;
            while(right + wordLen <= sLen){
                string s = 
            }
        }
    }
};
// @lc code=end

