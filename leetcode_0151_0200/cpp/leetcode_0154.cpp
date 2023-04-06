/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(true){
            while(left + 1 <= right && nums[left] == nums[left + 1])
                left++;
            while(right - 1 >= right && nums[right] == nums[right - 1])
                right--;
            int mid = (left + right) / 2;
            if(mid == left)
                return min(nums[left], nums[right]);
            if(nums[left] < nums[right])
                return nums[left];
            if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
    }
};
// @lc code=end

