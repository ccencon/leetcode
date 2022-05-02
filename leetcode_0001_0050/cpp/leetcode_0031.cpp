/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        for(; i > 0; i--){
            if(nums[i] <= nums[i - 1])
                continue;
            int rpc = nums.size() - 1;
            for(; rpc > i; rpc--)
                if(nums[rpc] > nums[i - 1])
                    break;
            swap(nums[i - 1], nums[rpc]);
            reverse(nums.begin() + i, nums.end());
            break;
        }
        if(i == 0)
            reverse(nums.begin(), nums.end());
    }
};
// @lc code=end

