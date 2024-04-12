/*
 * @lc app=leetcode.cn id=163 lang=cpp
 *
 * [163] 缺失的区间
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())
            return {{lower, upper}};
        vector<vector<int>> ret;
        for(auto n : nums){
            if(n > lower)
                ret.emplace_back(vector<int>{lower, n - 1});
            lower = n + 1;
        }
        if(nums.back() != upper)
            ret.emplace_back(vector<int>{nums.back() + 1, upper});
        return ret;
    }
};
// @lc code=end

