/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_map, rec_map;
        int num = 0;
        for(auto c : t){
            t_map[c]++;
            num += c;
        }
        queue<int> q;
        int sl = s.size(), length = INT32_MAX, left = 0;
        for(int i = 0; i < sl; i++){
            auto it = t_map.find(s[i]);
            if(it != t_map.end()){
                q.push(i);
                rec_map[s[i]]++;
                if(rec_map[s[i]] <= it->second){
                    num -= s[i];
                    if(num == 0){
                        while(rec_map[s[q.front()]] > t_map[s[q.front()]]){
                            rec_map[s[q.front()]]--;
                            q.pop();
                        }
                        if(length > q.back() - q.front()){
                            left = q.front();
                            length = q.back() - left;
                        }
                        num += s[q.front()];
                        rec_map[s[q.front()]]--;
                        q.pop();
                    }
                }
            }
        }
        return length == INT32_MAX ? "" : s.substr(left, length + 1);
    }
};
// @lc code=end

