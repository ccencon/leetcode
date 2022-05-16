/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0, idx = 0, length = nums.size();
        while(idx < length - 1){
            int range = min(idx + nums[idx] + 1, length);
            int next = idx + 1, num = nums[next];
            for(int i = idx + 2; i < range; i++)
                if(--num < nums[i]){
                    num = nums[i];
                    next = i;
                }
            step++;
            if(range == length)
                break;
            idx = next;
        }
        return step;
    }
};
// @lc code=end

