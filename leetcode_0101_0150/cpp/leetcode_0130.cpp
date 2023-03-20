/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <functional>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int h = board.size(), l = board[0].size();
        vector<int> union_set(h * l);
        iota(union_set.begin(), union_set.end(), 0);
        function<int(int)> union_root = [&](int idx){
            return idx == union_set[idx] ? idx : (union_set[idx] = union_root(union_set[idx]));
        };
        function<void(int, int)> union_merge = [&](int idx1, int idx2){
            union_set[union_root(idx2)] = union_set[union_root(idx1)];
        };
        for(int i = 0; i < h; i++)
            for(int j = 0; j < l; j++)
                if(board[i][j] == 'O'){
                    int idx = i * l + j;
                    if(i == 0 || i == h - 1 || j == 0 || j == l - 1)
                        union_merge(0, idx);
                    if(j > 0 && board[i][j - 1] == 'O')
                        union_merge(idx - 1, idx);
                    if(i > 0 && board[i - 1][j] == 'O')
                        union_merge(idx - l, idx);
                }
        for(int i = 0; i < h; i++)
            for(int j = 0; j < l; j++)
                if(board[i][j] == 'O' && union_root(i * l + j) != union_root(0))
                    board[i][j] = 'X';
    }
};
// @lc code=end

