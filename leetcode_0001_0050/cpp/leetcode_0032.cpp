/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int length = 0, count = 0, _l = 0, sl = s.length();
//         for(int i = 0; i < sl; i++){
//             if(s[i] == '('){
//                 count++;
//                 _l++;
//             }
//             else{
//                 if(count == 0){
//                     length = max(length, _l);
//                     _l = 0;
//                     continue;
//                 }
//                 count--;
//                 _l++;
//                 if(count == 0)
//                     length = max(length, _l);
//             }
//         }
//         count = _l = 0;
//         for(int i = sl - 1; i >= 0; i--){
//             if(s[i] == ')'){
//                 count++;
//                 _l++;
//             }
//             else{
//                 if(count == 0){
//                     length = max(length, _l);
//                     _l = 0;
//                     continue;
//                 }
//                 count--;
//                 _l++;
//                 if(count == 0)
//                     length = max(length, _l);
//             }
//         }
//         return length;
//     }
// };

//dp
class Solution {
public:
    int longestValidParentheses(string s) {
        int length = 0, sl = s.length();
        vector<int> dp(sl + 1, 0);//trick，方便理解应该是初始sl容量，设置当前i，这里初始多1，可以减少分支判断
        for(int i = 1; i < sl; i++){
            if(s[i] == '(')//当前'('必然是匹配后面的')'，故忽略
                continue;
            if(s[i - 1] == '(')
                dp[i + 1] = dp[i - 1] + 2;
            else if(i - dp[i] > 0 && s[i - dp[i] - 1] == '(')
                dp[i + 1] = dp[i] + 2 + dp[i - dp[i] - 1];
            length = max(length, dp[i + 1]);
        }
        return length;
    }
};
// @lc code=end

