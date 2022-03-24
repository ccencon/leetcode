/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tmpNums;
        for(vector<int>::size_type i = 0; i < nums.size(); i++){
            if (tmpNums.find(target - nums[i]) != tmpNums.end())
                return {(int)i, tmpNums[target - nums[i]]};
            tmpNums[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

