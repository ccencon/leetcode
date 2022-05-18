/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = nums[0], ans = prev;
        for(int i = 1; i < nums.size(); i++){
            prev = max(nums[i], nums[i] + prev);
            ans = max(ans, prev);
        }
        return ans;
    }
};
// @lc code=end

