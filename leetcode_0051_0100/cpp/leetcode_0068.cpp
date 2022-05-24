/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        string tmp(maxWidth, ' ');
        int wsl = words.size();
        for(int i = 0; i < wsl;){
            fill(tmp.begin(), tmp.end(), ' ');
            int right = i + 1, length = words[i].length();
            while(right < wsl && length + words[right].length() + right - i <= maxWidth){
                length += words[right].length();
                right++;
            }
            int index = 0;
            if(right == wsl){
                for(int j = i; j < right; j++){
                    copy(words[j].begin(), words[j].end(), tmp.begin() + index);
                    index += words[j].length() + 1;
                }
            }
            else{
                int spaces = maxWidth - length;
                for(int j = i; j < right; j++){
                    copy(words[j].begin(), words[j].end(), tmp.begin() + index);
                    if(j != right - 1){
                        int curSpaces = spaces / (right - j - 1);
                        if(curSpaces * (right - j - 1) != spaces)
                            curSpaces++;
                        index += words[j].length() + curSpaces;
                        spaces -= curSpaces;
                    }
                }
            }
            ans.emplace_back(tmp);
            i = right;
        }
        return ans;
    }
};
// @lc code=end

