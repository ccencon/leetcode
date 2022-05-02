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
        vector<int> ret;
        int sLen = s.size(), wordLen = words[0].size(), wordsCount = words.size();
        for(int i = 0; i < wordLen; i++){
            int left = i, right = i, matchCount = 0;
            while(right + wordLen <= sLen){
                string subs = s.substr(right, wordLen);
                auto it = wordsMap.find(subs);
                if(it == wordsMap.end()){
                    left = right = right + wordLen;
                    matchCount = 0;
                    usedMap.clear();
                }
                else{
                    while(it->second == usedMap[subs]){
                        usedMap[s.substr(left, wordLen)]--;
                        left += wordLen;
                        matchCount--;
                    }
                    right += wordLen;
                    usedMap[subs]++;
                    matchCount++;
                    if(matchCount == wordsCount)
                        ret.push_back(left);
                }
            }
            usedMap.clear();
        }
        return ret;
    }
};
// @lc code=end

