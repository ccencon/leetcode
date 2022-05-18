/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> row(n, n), column(n, n);
        vector<bool> dia_r(2 * n - 1, false), dia_l(2 * n - 1, false);
        int trace_i = 0, trace_j = 0, ans = 0;
        while(trace_i >= 0){
            for(; trace_i < n; trace_i++){
                for(int j = trace_j; j < n; j++){
                    if(column[j] != n || dia_r[trace_i + j] || dia_l[n - 1 - trace_i + j])
                        continue;
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
                ans++;
            trace_i--;
            do{
                trace_j = row[trace_i];
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

