/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> tmp(n, string(n, '.'));
        vector<int> row(n, n), column(n, n);
        vector<bool> dia_r(2 * n - 1, false), dia_l(2 * n - 1, false);
        int trace_i = 0, trace_j = 0;
        while(trace_i >= 0){
            for(; trace_i < n; trace_i++){
                for(int j = trace_j; j < n; j++){
                    if(column[j] != n || dia_r[trace_i + j] || dia_l[n - 1 - trace_i + j])
                        continue;
                    tmp[trace_i][j] = 'Q';
                    row[trace_i] = j;
                    column[j] = trace_i;
                    dia_r[trace_i + j] = true;
                    dia_l[n - 1 - trace_i + j] = true;
                    break;
                }
                if(row[trace_i] == n)
                    break;
                trace_j = 0;
            }
            if(trace_i == n)
                ans.emplace_back(tmp);
            trace_i--;
            do{
                trace_j = row[trace_i];
                tmp[trace_i][trace_j] = '.';
                row[trace_i] = n;
                column[trace_j] = n;
                dia_r[trace_i + trace_j] = false;
                dia_l[n - 1 - trace_i + trace_j] = false;
                if(++trace_j == n)
                    trace_i--;
            }while(trace_i >= 0 && trace_j == n);
        }
        return ans;
    }
};
// @lc code=end

