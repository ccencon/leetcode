/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
// class Solution {
// public:
// 	int largestRectangleArea(vector<int>& heights) {
// 		stack<int> st;
//         int hl = heights.size(), maxRA = 0;
//         vector<int> right(hl), left(hl, 0);
//         for(int i = hl - 1; i >= 0; i--){
//             while(!st.empty() && heights[i] <= heights[st.top()]){
//                 left[st.top()] = i + 1;
//                 st.pop();
//             }
//             right[i] = st.empty() ? hl : st.top();
//             st.emplace(i);
//         }
//         for(int i = 0; i < hl; i++)
//             maxRA = max(maxRA, heights[i] * (right[i] - left[i]));
//         return maxRA;
//     }
// };
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        int maxArea=0;
        stack<int> s;
        heights.push_back(0);//保证将最后一个方块的面积算上
        for(int i=0;i < heights.size();++i){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                int cur=s.top(); s.pop();
                maxArea = max(maxArea, heights[cur]*(s.empty()?i:(i-s.top()-1)));
            }
            s.push(i);
        }
        return maxArea;
    }
};
// @lc code=end

