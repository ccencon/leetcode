/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, ns = right;
        for(int i = 0; i < ns; i++)
            if(nums[i] > nums[i + 1]){
                if(target >= nums[0]){
                    left = 0; right = i;
                }else{
                    left = i + 1; right = ns;
                }
                break;
            }
        while(true){
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            if(left >= right)
                return -1;
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
};
// @lc code=end

