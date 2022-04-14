/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int last = (int)nums.size() - 1;
        int k = 0;
        while(k <= last){
            if(nums[k] == val){
                while(last >= k && nums[last] == val)
                    last--;
                if(last < k)
                    return k;
                swap(nums[k], nums[last--]);
            }
            k++;
        }
        return k;
    }
};
// @lc code=end

