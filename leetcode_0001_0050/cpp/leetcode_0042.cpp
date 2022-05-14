/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, hs = height.size();
        stack<int> edge;
        for(int i = 0; i < hs; i++){
            if(height[i] == 0)
                continue;
            if(edge.empty()){
                edge.push(i);
                continue;
            }
            if(height[i] < height[i - 1]){
                edge.push(i);
                continue;
            }
            int prev = edge.top(), h = height[i - 1];
            while(height[prev] < height[i]){
                edge.pop();
                ans += (height[prev] - h) * (i - prev - 1);
                if(edge.empty())
                    break;
                h = height[prev];
                prev = edge.top();
            }
            if(!edge.empty())
                ans += (height[i] - h) * (i - prev - 1);
            edge.push(i);
        }
        return ans;
    }
};
// @lc code=end

