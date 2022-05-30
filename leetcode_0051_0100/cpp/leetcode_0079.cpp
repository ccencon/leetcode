/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
using namespace std;
//未优化版
// class Solution {
// public:
// 	bool exist(vector<vector<char>>& board, string word) {
// 		int height = board.size(), width = board[0].size(), wl = word.length();
// 		vector<vector<bool>> visited(height, vector<bool>(width, false));
// 		function<bool(int, int, int)> dfs = [&](int i, int j, int idx){
// 			if (idx >= wl)
// 				return true;
// 			if (i < 0 || i >= height || j < 0 || j >= width)
// 				return false;
// 			if (visited[i][j])
// 				return false;
// 			if (board[i][j] != word[idx])
// 				return false;
// 			visited[i][j] = true;
// 			if (dfs(i - 1, j, idx + 1))
// 				return true;
// 			if (dfs(i, j + 1, idx + 1))
// 				return true;
// 			if (dfs(i + 1, j, idx + 1))
// 				return true;
// 			if (dfs(i, j - 1, idx + 1))
// 				return true;
// 			visited[i][j] = false;
// 			return false;
// 		};
// 		for (int i = 0; i < height; i++)
// 			for (int j = 0; j < width; j++)
// 				if (dfs(i, j, 0))
// 					return true;
// 		return false;
// 	}
// };
//剪枝优化版本，不过提交的运行时间更高，这应该是测试用例问题，如果board中存在较多重复的匹配集，这版本的效率应该会更高
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int height = board.size(), width = board[0].size(), wl = word.length();
		vector<vector<int>> flag(height, vector<int>(width, 0));
		vector<vector<bool>> visited(height, vector<bool>(width, false));
		function<int(int, int, int)> dfs = [&](int i, int j, int idx){
			if (idx >= wl)
				return 1;
			if (i < 0 || i >= height || j < 0 || j >= width)
				return 0;
			if (visited[i][j])
				return 0;
			if (flag[i][j] & (1 << idx))
				return -1;
			if (board[i][j] != word[idx])
				return -1;
			visited[i][j] = true;
			int status1 = dfs(i - 1, j, idx + 1);
			if (status1 == 1)
				return 1;
			int status2 = dfs(i, j + 1, idx + 1);
			if (status2 == 1)
				return 1;
			int status3 = dfs(i + 1, j, idx + 1);
			if (status3 == 1)
				return 1;
			int status4 = dfs(i, j - 1, idx + 1);
			if (status4 == 1)
				return 1;
			visited[i][j] = false;
			if (status1 + status2 + status3 + status4 == -4)
				flag[i][j] |= 1 << idx;
			return 0;
		};
		for (int i = 0; i < height; i++)
		    for (int j = 0; j < width; j++)
		        if (dfs(i, j, 0) == 1)
			        return true;
		return false;
	}
};
// @lc code=end

