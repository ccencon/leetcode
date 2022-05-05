/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        if(nums[right] != target)
            return {-1, -1};
        vector<int> ret(2, right);
        left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right + 1) / 2;
            if(nums[mid] <= target)
                left = mid;
            else
                right = mid - 1;
        }
        ret[1] = left;
        return ret;
    }
};
// @lc code=end

