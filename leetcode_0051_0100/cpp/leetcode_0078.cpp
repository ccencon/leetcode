/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int ns = nums.size(), num = pow(2, ns);
        vector<vector<int>> ans(num);
        for(int i = 0; i < num; i++)
            for(int f = 0; f < ns; f++)
                if(i & (1 << f))
                    ans[i].push_back(nums[f]);
        return ans;
    }
};
// @lc code=end

