/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for(int v : nums)
            sum ^= v;
        return sum;
    }
};
// @lc code=end

