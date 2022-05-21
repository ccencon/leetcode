/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
		int rects = (n + 1) >> 1;
		vector<int> outNums(rects); outNums[0] = 0;
		int shellNums = (n - 1) << 2;
		for (int l = 0; l < rects - 1; l++)
			outNums[l + 1] = outNums[l] + shellNums - (l << 3);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				int _i = (i < rects) ? i : n - i - 1;
				int _j = (j < rects) ? j : n - j - 1;
				int l = (_j <= _i && _j < rects) ? _j : _i;
                if(i == l || j == n - 1 - l)
                    ans[i][j] = outNums[l] + i - l + j - l + 1;
                else
                    ans[i][j] = outNums[l] + shellNums - (l << 3) - i - j + l + l + 1;
			}
		}
		return ans;
    }
};
// @lc code=end

