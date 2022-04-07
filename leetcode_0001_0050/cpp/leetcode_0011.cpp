/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, maxArea = 0;
        while(i < j){
            int h = min(height[i], height[j]);
            maxArea = max(maxArea, h * (j - i));
            if(height[i] == h)
                i++;
            else
                j--;
        }
        return maxArea;
    }
};
// @lc code=end

