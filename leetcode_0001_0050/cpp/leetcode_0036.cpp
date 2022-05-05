/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
#include <vector>
#include <cstring>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[10] = {0}, column[9][10] = {{0}}, grids[9][10] = {{0}};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')
                    continue;
                int idx = board[i][j] - '0';
                if(++row[idx] > 1)
                    return false;
                if(++column[j][idx] > 1)
                    return false;
                if(++grids[i / 3 * 3 + j / 3][idx] > 1)
                    return false;
            }
            memset(row, 0, sizeof(row));
        }
        return true;
    }
};
// @lc code=end

