/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int height = matrix.size(), width = matrix[0].size();
		int rects = (min(height, width) + 1) >> 1;
		vector<int> outNums(rects), ans(height * width); outNums[0] = 0;
		int shellNums = ((height - 1) << 1) + ((width - 1) << 1);
		for (int l = 0; l < rects - 1; l++)
			outNums[l + 1] = outNums[l] + shellNums - (l << 3);
		for (int i = 0; i < height; i++){
			for (int j = 0; j < width; j++){
				int _i = (i < (height + 1) >> 1) ? i : height - i - 1;
				int _j = (j < (width + 1) >> 1) ? j : width - j - 1;
				int l = (_j <= _i && _j < rects) ? _j : _i;
                if(i == l || j == width - 1 - l)
                    ans[outNums[l] + i - l + j - l] = matrix[i][j];
                else
                    ans[outNums[l] + shellNums - (l << 3) - i - j + l + l] = matrix[i][j];
			}
		}
		return ans;
	}
};
// @lc code=end

