/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(true){
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

