/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ns = nums.size(), back = 0, forward = -1;
        while(++forward < ns){
            int pivot = forward;
            while(forward + 1 < ns && nums[forward + 1] == nums[pivot])
                forward++;
            for(int count = min(1, forward - pivot); count >= 0; count--, pivot++, back++)
                nums[back] = nums[pivot];
        }
        return back;
    }
};
// @lc code=end

