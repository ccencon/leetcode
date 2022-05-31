/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] == nums[left] && nums[mid] == nums[right]){
                left++; right--;
            }
            else if(target < nums[mid]){
                if(target <= nums[right] && nums[mid] > nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else if(target > nums[mid]){
                if(target >= nums[left] && nums[mid] < nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

