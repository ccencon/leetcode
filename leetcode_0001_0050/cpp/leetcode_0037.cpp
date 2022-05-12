/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <functional>
using namespace std;
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		unsigned int bits[9][9] = { [0 ... 8] = { [0 ... 8] = 0x1ff } };
		function<void(int, int)> number_handler = [&](int i, int j) {
			if (board[i][j] == '.')
				return;
			auto point_handler = [&](int __i, int __j){
				if (board[__i][__j] != '.')
					return;
				bits[__i][__j] = min(bits[__i][__j], bits[__i][__j] ^ (1 << (board[i][j] - '0' - 1)));
				if ((bits[__i][__j] & (bits[__i][__j] - 1)) == 0){
					board[__i][__j] = __builtin_ffs(bits[__i][__j]) + '0';
					number_handler(__i, __j);
				}
			};
			bits[i][j] = 0;
			for (int idx = 0; idx < 9; idx++){
				point_handler(i, idx);
				point_handler(idx, j);
			}
			for (int _i = i / 3 * 3; _i < i / 3 * 3 + 3; _i++)
				for (int _j = j / 3 * 3; _j < j / 3 * 3 + 3; _j++)
					point_handler(_i, _j);
		};
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				number_handler(i, j);

		vector<pair<int, int>> unsure_set;
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				if (bits[i][j] != 0)
					unsure_set.emplace_back(i, j);
		function<bool(int)> unsure_handler = [&](int loc) {
			if (loc == unsure_set.size())
				return true;
			int i = unsure_set[loc].first, j = unsure_set[loc].second;
			unsigned int bit = bits[i][j], index = 0;
			while (bit > 0){
				index += __builtin_ffs(bit);
				unsigned int flag = 1 << (index - 1);
				board[i][j] = index + '0';
				vector<pair<int, int>> rec;
                auto insert_func = [&](int ii, int jj){
                    if (board[ii][jj] == '.' && (bits[ii][jj] & flag) != 0){
						bits[ii][jj] ^= flag;
						rec.emplace_back(ii, jj);
					}
                };
				for (int idx = 0; idx < 9; idx++){
					insert_func(i, idx);
					insert_func(idx, j);
				}
                for (int _i = i / 3 * 3; _i < i / 3 * 3 + 3; _i++)
					for (int _j = j / 3 * 3; _j < j / 3 * 3 + 3; _j++)
						insert_func(_i, _j);
				if (unsure_handler(loc + 1))
					return true;
				for (const auto& p : rec)
					bits[p.first][p.second] |= flag;
				board[i][j] = '.';
				bit = bits[i][j] >> index;
			}
			return false;
		};
		unsure_handler(0);
	}
};
// @lc code=end

