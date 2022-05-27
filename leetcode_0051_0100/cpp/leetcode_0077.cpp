/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp(k);
        for(int i = 1; i < k; i++)
            tmp[i - 1] = i;
        int traceIdx = 0;
        while(traceIdx >= 0){
            for(int i = (k == 1 ? 0 : tmp[k - 2]) + 1; i <= n; i++){
                tmp[k - 1] = i;
                ans.emplace_back(tmp);
            }
            for(traceIdx = k - 2; traceIdx >= 0; traceIdx--){
                if(++tmp[traceIdx] + k - traceIdx - 1 <= n){
                    for(int j = traceIdx + 1; j < k - 1; j++)
                        tmp[j] = tmp[j - 1] + 1;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

