/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), columns = matrix[0].size();
        vector<bool> row_flag(rows, false);
        unordered_set<int> column_flag;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < columns; j++)
                if(matrix[i][j] == 0){
                    row_flag[i] = true;
                    column_flag.insert(j);
                }
        for(int i = 0; i < rows; i++){
            if(row_flag[i])
                for(int j = 0; j < columns; j++)
                    matrix[i][j] = 0;
            else
                for(auto j : column_flag)
                    matrix[i][j] = 0;
        }
    }
};
// @lc code=end

