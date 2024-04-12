/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if((mid == 0 || nums[mid] > nums[mid - 1]) && nums[mid] > nums[mid + 1])
                return mid;
            if(mid == 0 || nums[mid + 1] >= nums[mid - 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
// @lc code=end

