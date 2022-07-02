/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp; int nl = nums.size();
        function<void(int)> dfs = [&](int idx){
            if(idx >= nl){
                ans.emplace_back(tmp);
                return;
            }
            int dupIdx = idx;
            for(; dupIdx + 1 < nl && nums[dupIdx + 1] == nums[idx]; dupIdx++){}
            if(dupIdx == idx){
                tmp.push_back(nums[idx]);
                dfs(idx + 1);
                tmp.pop_back();
                dfs(idx + 1);
            }
            else{
                int size = tmp.size();
                for(int diff = dupIdx - idx + 1; diff >= 0; diff--){
                    tmp.resize(size + diff, nums[idx]);
                    dfs(dupIdx + 1);
                }
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

