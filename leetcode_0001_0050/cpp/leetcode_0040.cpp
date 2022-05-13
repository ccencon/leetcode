/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int traceIdx = 0, cs = candidates.size();
        vector<vector<int>> ans;
        vector<bool> visited(cs, false);
        while(true){
            for(; traceIdx < cs; traceIdx++)
                if(candidates[traceIdx] > target)
                    break;
            if(target == 0){
                ans.push_back({});
                vector<int>& ref = ans[ans.size() - 1];
                for(int i = traceIdx - 1; i >= 0; i--)
                    if(visited[i])
                        ref.push_back(candidates[i]);
            }
            while(--traceIdx >= 0 && visited[traceIdx]){
                visited[traceIdx] = false;
                target += candidates[traceIdx];
            }
            if(traceIdx >= 0){
                int basis = candidates[traceIdx];
                do{
                    visited[traceIdx] = true;
                    target -= candidates[traceIdx];
                    traceIdx++;
                }while(traceIdx < cs && candidates[traceIdx] == basis);
            }
            else
                break;
        }
        return ans;
    }
};
// @lc code=end

