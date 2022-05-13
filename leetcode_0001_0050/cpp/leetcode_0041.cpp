/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ns = nums.size();
        for(int i = 0; i < ns; i++)
            while(nums[i] > 0 && nums[i] <= ns && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for(int i = 0; i < ns; i++)
            if(nums[i] != i + 1)
                return i + 1;
        return ns + 1;
    }
};
// @lc code=end

