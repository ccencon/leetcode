/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs){
            return lhs[0] < rhs[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> ans;
        vector<int> tmp(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= tmp[1])
                tmp[1] = max(tmp[1], intervals[i][1]);
            else{
                ans.emplace_back(tmp);
                tmp = intervals[i];
            }
        }
        ans.emplace_back(tmp);
        return ans;
    }
};
// @lc code=end

