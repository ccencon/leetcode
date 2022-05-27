/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, p2 = nums.size() - 1, pm = 0;
        while(pm <= p2){
            if(nums[pm] == 2){
                swap(nums[pm], nums[p2]);
                p2--;
            }
            else if(nums[pm] == 0){
                if(pm == p0){
                    pm++;
                    p0++;
                }
                else{
                    swap(nums[pm], nums[p0]);
                    p0++;
                }
            }
            else
                pm++;
        }
    }
};
// @lc code=end

