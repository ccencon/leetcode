/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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
            return 0;
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
                for(auto v : vexs[vex])
                    if(!visited[v])
                        tmps.emplace(v);
            }
            if(found) break;
            for(auto v : tmps){
                visited[v] = true;
                que.emplace(v);
            }
            length++;
        }
        return found ? length : 0;
    }
};
// @lc code=end

