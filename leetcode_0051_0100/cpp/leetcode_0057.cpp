/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty())
            return {newInterval};
        int beginIdx = -1, endIdx = intervals.size() - 1;
        for(int i = 0; i <= endIdx; i++){
            if(newInterval[0] <= intervals[i][1]){
                beginIdx = i;
                break;
            }
        }
        if(beginIdx == -1){
            intervals.emplace_back(newInterval);
            return intervals;
        }
        for(int i = beginIdx; i <= endIdx; i++){
            if(newInterval[1] < intervals[i][0]){
                endIdx = i - 1;
                break;
            }
        }
        if(endIdx == -1){
            intervals.emplace(intervals.begin(), newInterval);
            return intervals;
        }
        if(endIdx < beginIdx){
            intervals.emplace(intervals.begin() + beginIdx, newInterval);
            return intervals;
        }
        intervals[beginIdx][0] = min(intervals[beginIdx][0], newInterval[0]);
        intervals[beginIdx][1] = max(intervals[endIdx][1], newInterval[1]);
        copy(intervals.begin() + endIdx + 1, intervals.end(), intervals.begin() + beginIdx + 1);
        intervals.resize(intervals.size() - endIdx + beginIdx);
        return intervals;
    }
};
// @lc code=end

