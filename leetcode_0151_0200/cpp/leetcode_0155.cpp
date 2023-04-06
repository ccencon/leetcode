/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
#include <stack>
using namespace std;
class MinStack {
    stack<long long> st;
    long long min;
public:
    MinStack() {

    }
    
    void push(int val) {
        if(st.empty()){
            st.emplace(0);
            min = val;
            return;
        }
        st.emplace(val - min);
        min = val < min ? val : min;
    }
    
    void pop() {
        if(st.top() < 0)
            min -= st.top();
        st.pop();
    }
    
    int top() {
        return int(st.top() < 0 ? min : st.top() + min);
    }
    
    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

