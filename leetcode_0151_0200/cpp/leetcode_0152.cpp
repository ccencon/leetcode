/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int length = nums.size(), idx = -1, _max = nums[0];
        vector<int> sums(length + 1, 1);
        for(int l = 0; l < length; l++){
            if(nums[l] == 0){
                idx = -1;
                _max = max(_max, 0);
                continue;
            }
            sums[l + 1] = nums[l] * sums[l];
            _max = max(_max, sums[l + 1]);
            if(sums[l + 1] < 0){
                if(idx == -1)
                    idx = l;
                else
                    _max = max(_max, sums[l + 1] / sums[idx + 1]);
            }
        }
        return _max;
	}
};
// @lc code=end

