/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ns = nums.size(), as = 1, ansi = 0, traceIdx;
        for(int i = 2; i <= ns; i++)
            as *= i;
        vector<vector<int>> ans(as, vector<int>(ns));
        do{
            for(int i = 0; i < ns; i++)
                ans[ansi][i] = nums[i];
            ansi++;
            traceIdx = ns - 2;
            for(; traceIdx >= 0; traceIdx--){
                if(nums[traceIdx] >= nums[traceIdx + 1])
                    continue;
                for(int i = ns - 1; i > traceIdx; i--)
                    if(nums[i] > nums[traceIdx]){
                        swap(nums[i], nums[traceIdx]);
                        break;
                    }
                reverse(nums.begin() + traceIdx + 1, nums.end());
                break;
            }
        }while(traceIdx != -1);
        ans.resize(ansi);
        return ans;
    }
};
// @lc code=end

