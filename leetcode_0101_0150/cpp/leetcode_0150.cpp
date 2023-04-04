/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(const auto& s : tokens){
            if(s.size() == 1 && (s[0] < '0' || s[0] > '9')){
                switch(s[0]){
                    case '+':{
                        int right = st.top(); st.pop();
                        int left = st.top(); st.pop();
                        st.emplace(left + right);
                        break;
                    }
                    case '-': {
                        int right = st.top(); st.pop();
                        int left = st.top(); st.pop();
                        st.emplace(left - right);
                        break;
                    }
                    case '*':{
                        int right = st.top(); st.pop();
                        int left = st.top(); st.pop();
                        st.emplace(left * right);
                        break;
                    }
                    case '/':{
                        int right = st.top(); st.pop();
                        int left = st.top(); st.pop();
                        st.emplace(left / right);
                        break;
                    }
                    default:{
                        break;
                    }
                }
            }
            else{
                st.emplace(atoi(s.data()));
            }
        }
        return st.top();
    }
};
// @lc code=end

