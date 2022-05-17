/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int ns = nums.size(), as = 1, ansi = 0, traceIdx;
        for(int i = 2; i <= ns; i++)
            as *= i;
        vector<vector<int>> ans(as, vector<int>(ns));
        vector<int> idxPermt(ns);
        for(int i = 0; i < ns; i++)
            idxPermt[i] = i;
        do{
            for(int i = 0; i < ns; i++)
                ans[ansi][i] = nums[idxPermt[i]];
            ansi++;
            traceIdx = ns - 2;
            for(; traceIdx >= 0; traceIdx--){
                if(idxPermt[traceIdx] > idxPermt[traceIdx + 1])
                    continue;
                for(int i = ns - 1; i > traceIdx; i--)
                    if(idxPermt[i] > idxPermt[traceIdx]){
                        swap(idxPermt[i], idxPermt[traceIdx]);
                        break;
                    }
                reverse(idxPermt.begin() + traceIdx + 1, idxPermt.end());
                break;
            }
        }while(traceIdx != -1);
        return ans;
    }
};
// @lc code=end

