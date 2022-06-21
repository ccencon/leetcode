/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
#include <string>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;
// class Solution {
//     unordered_map<string, bool> rec;
// public:
//     bool isScramble(string s1, string s2) {
//         int length = s1.length();
//         if(length == 1)
//             return s1 == s2;
//         auto sm = s1 + s2;
//         auto it = rec.find(sm);
//         if(it != rec.end())
//             return it->second;
//         string _s1_l, _s1_r, _s2;
//         for(int i = 0; i < length - 1; i++){
//             _s1_l.push_back(s1[i]);
//             _s2.push_back(s2[i]);
//             sort(_s1_l.begin(), _s1_l.end());
//             sort(_s2.begin(), _s2.end());
//             if(_s1_l == _s2 && isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1))
//                 && isScramble(s1.substr(i + 1, length - 1 - i), s2.substr(i + 1, length - 1 - i))){
//                     rec[sm] = true;
//                     return true;
//                 }
//             _s1_r.push_back(s1[length - 1 - i]);
//             sort(_s1_r.begin(), _s1_r.end());
//             if(_s1_r == _s2 && isScramble(s1.substr(0, length - 1 - i), s2.substr(i + 1, length - 1 - i))
//                 && isScramble(s1.substr(length - 1 - i, i + 1), s2.substr(0, i + 1))){
//                     rec[sm] = true;
//                     return true;
//                 }
//         }
//         rec[sm] = false;
//         return false;
//     }
// };
//优化版本
class Solution {
    void insert(string& s, char c){
        if(s.empty()){
            s.push_back(c);
            return;
        }
        int left = 0, right = s.length() - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(s[mid] == c){
                s.insert(mid, 1, c);
                return;
            }
            if(s[mid] < c)
                left = mid + 1;
            else
                right = mid - 1;
        }
        s.insert(s[left] < c ? left + 1 : left, 1, c);
    }
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string, bool> rec;
        function<bool(int, int, int)> dfs = [&](int i1, int i2, int length){
            if(length == 1)
                return s1[i1] == s2[i2];
            auto sm = s1.substr(i1, length) + s2.substr(i2, length);
            auto it = rec.find(sm);
            if(it != rec.end())
                return it->second;
            string _s1_l, _s1_r, _s2;
            for(int i = 0; i < length - 1; i++){
                insert(_s1_l, s1[i1 + i]);
                insert(_s2, s2[i2 + i]);
                if(_s1_l == _s2 && dfs(i1, i2, i + 1) && dfs(i1 + i + 1, i2 + i + 1, length - i - 1)){
                    rec[sm] = true;
                    return true;
                }
                insert(_s1_r, s1[length + i1 - 1 - i]);
                if(_s1_r == _s2 && dfs(length + i1 - 1 - i, i2, i + 1) && dfs(i1, i2 + i + 1, length - i - 1)){
                    rec[sm] = true;
                    return true;
                }
            }
            rec[sm] = false;
            return false;
        };
        return dfs(0, 0, s1.length());
    }
};
// @lc code=end

