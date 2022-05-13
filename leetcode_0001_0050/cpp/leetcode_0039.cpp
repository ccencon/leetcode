/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());//减少递归深度
        function<void(int, int)> cal_func = [&](int pos, int _t){
            if(_t == 0){
                ans.push_back({});
                return;
            }
            if(pos == candidates.size() || _t < candidates[pos])
                return;
            int count = _t / candidates[pos];
            for(int i = 0; i <= count; i++){
                int ans_size = ans.size();
                cal_func(pos + 1, _t);
                if(ans_size != ans.size() && i != 0)//匹配成功
                    for(int s = ans_size; s < ans.size(); s++)
                        fill_n(back_inserter(ans[s]), i, candidates[pos]);
                _t -= candidates[pos];
            }
        };
        cal_func(0, target);
        return ans;
    }
};
// @lc code=end

