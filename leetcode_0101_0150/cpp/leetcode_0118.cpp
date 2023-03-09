/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>(1, 1));
        for(int i = 1; i < numRows; i++){
            for(int j = 1; j < i; j++)
                ans[i].emplace_back(ans[i - 1][j - 1] + ans[i - 1][j]);
            ans[i].emplace_back(1);
        }
        return ans;
    }
};
// @lc code=end

