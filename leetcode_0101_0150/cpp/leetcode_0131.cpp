/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; vector<string> sub;
        int sl = s.size();
        function<bool(int, int)> isPalindrome = [&](int idx1, int idx2){
            while(idx1 < idx2){
                if(s[idx1] != s[idx2])
                    return false;
                idx1++; idx2--;
            }
            return true;
        };
        vector<vector<int>> mem(sl, vector<int>(sl, -1));
        function<void(int)> helper = [&](int idx){
            if(idx >= sl){
                ans.emplace_back(sub);
                return;
            }
            for(int length = 1; idx + length <= sl; length++){
                if(mem[idx][idx + length - 1] == -1){
                    if(isPalindrome(idx, idx + length - 1))
                        mem[idx][idx + length - 1] = 1;
                    else
                        mem[idx][idx + length - 1] = 0;
                }
                if(mem[idx][idx + length - 1] == 0)
                    continue;
                sub.emplace_back(s.substr(idx, length));
                helper(idx + length);
                sub.pop_back();
            }
        };
        helper(0);
        return ans;
    }
};
// @lc code=end

