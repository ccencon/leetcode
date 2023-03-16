/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isConnected(const string& a, const string& b) const {
        bool flag = false;
        for(size_t i = 0; i < a.size(); i++){
            if(a[i] != b[i]){
                if(flag)
                    return false;
                flag = true;
            }
        }
        return true;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int beginIdx = -1, endIdx = -1, wl = wordList.size();
        for(int i = 0; i < wl; i++){
            if(beginIdx == -1 && beginWord == wordList[i])
                beginIdx = i;
            else if (endIdx == -1 && endWord == wordList[i])
                endIdx = i;
            if(beginIdx != -1 && endIdx != -1)
                break;
        }
        if(endIdx == -1)
            return {};
        if(beginIdx == -1){
            wordList.emplace_back(beginWord);
            beginIdx = wl++;
        }
        vector<vector<int>> vexs(wl);
        for(int i = 0; i < wl; i++){
            for(int j = i + 1; j < wl; j++)
                if(isConnected(wordList[i], wordList[j])){
                    vexs[i].emplace_back(j);
                    vexs[j].emplace_back(i);
                }
        }
        queue<int> que; que.emplace(beginIdx);
        vector<bool> visited(wl, false); visited[beginIdx] = true;
        vector<vector<int>> path(wl);
        vector<vector<string>> ans;
        int length = 1; bool found = false;
        while(!que.empty()){
            int size = que.size();
            unordered_set<int> tmps;
            for(int i = 0; i < size; i++){
                int vex = que.front(); que.pop();
                if(vex == endIdx){
                    found = true;
                    break;
                }
                for(auto v : vexs[vex]){
                    if(!visited[v]){
                        path[v].emplace_back(vex);
                        tmps.emplace(v);
                    }
                }
            }
            if(found) break;
            for(auto v : tmps){
                visited[v] = true;
                que.emplace(v);
            }
            length++;
        }
        if(found){
            vector<string> sub(length); sub[0] = beginWord;
            function<void(int, int)> helper = [&](int vex, int idx){
                if(idx == 0){
                    ans.emplace_back(sub);
                    return;
                }
                sub[idx] = wordList[vex];
                for(auto v : path[vex])
                    helper(v, idx - 1);
            };
            helper(endIdx, length - 1);
        }
        return ans;
    }
};
// @lc code=end

