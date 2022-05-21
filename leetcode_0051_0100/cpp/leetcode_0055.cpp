/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int pathLength = nums[0], maxIdx = nums.size() - 1;
        for(int i = 1; i <= maxIdx; i++){
            if(i > pathLength || pathLength >= maxIdx)
                break;
            pathLength = max(pathLength, i + nums[i]);
        }
        return pathLength >= maxIdx;
    }
};
// @lc code=end

