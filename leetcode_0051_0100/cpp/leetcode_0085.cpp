/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> s;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); ++i){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                int cur = s.top(); s.pop();
                maxArea = max(maxArea, heights[cur] * (s.empty() ? i : (i - s.top() - 1)));
            }
            s.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size(), maximal = 0;
        vector<int> rectangles(cols, 0);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '0')
                    rectangles[j] = 0;
                else
                    rectangles[j]++;
            }
            maximal = max(maximal, largestRectangleArea(rectangles));
        }
        return maximal;
    }
};
// @lc code=end

