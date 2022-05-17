/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n / 2; i++){
            for(int j = i; j < n - i - 1; j++){
                int _i = i, _j = j, value = matrix[_i][_j];
                for(int k = 1; k <= 4; k++){
                    int t = _i;
                    _i = _j;
                    _j = n - 1 - t;
                    swap(value, matrix[_i][_j]);
                }
            }
        }
    }
};
// @lc code=end

