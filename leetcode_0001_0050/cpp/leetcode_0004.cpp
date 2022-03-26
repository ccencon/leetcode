/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int GetKth(vector<int>& nums1, vector<int>& nums2, int k)//k从1开始
    {
        int sure_1 = 0, sure_2 = 0;//记录nums1&nums2已确认比集合第k位下标小的下标
        while(true){
            if (sure_1 == nums1.size())
                return nums2[sure_2 + k - 1];
            if (sure_2 == nums2.size())
                return nums1[sure_1 + k - 1];
            if (k == 1)//如果nums1&nums2不为空，k最后必然会减少到1
                return min(nums1[sure_1], nums2[sure_2]);
            int k_1 = min(int(nums1.size() - sure_1), k / 2);
            int k_2 = min(int(nums2.size() - sure_2), k - k_1);
            if (nums1[sure_1 + k_1 - 1] < nums2[sure_2 + k_2 - 1]){
                sure_1 += k_1;
                k -= k_1;
            }
            else{
                sure_2 += k_2;
                k -= k_2;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::size_type length = nums1.size() + nums2.size();
        if (length % 2 != 0)
            return GetKth(nums1, nums2, length / 2 + 1);
        return (GetKth(nums1, nums2, length / 2) + GetKth(nums1, nums2, length / 2 + 1)) / 2.0f;
    }
};
// @lc code=end

