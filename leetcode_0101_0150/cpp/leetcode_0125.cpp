/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }
            char l = s[left], r = s[right];
            if(isalpha(l))
                l = toupper(l);
            if(isalpha(r))
                r = toupper(r);
            if(l != r)
                return false;
            left++; right--;
        }
        return true;
    }
};
// @lc code=end

