/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m + n; m--; n--;
        while(--total >= 0){
            if(m >= 0 && n >= 0){
                if(nums1[m] >= nums2[n])
                    nums1[total] = nums1[m--];
                else
                    nums1[total] = nums2[n--];
            }
            else if(m >= 0)
                nums1[total] = nums1[m--];
            else
                nums1[total] = nums2[n--];
        }
    }
};
// @lc code=end

