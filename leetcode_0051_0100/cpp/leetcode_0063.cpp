/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size(), width = obstacleGrid[0].size();
        vector<vector<int>> dp(height, vector<int>(width));
        dp[0][0] = obstacleGrid[0][0] == 0;
        for(int j = 1; j < width; j++){
            if(obstacleGrid[0][j] == 1)
                dp[0][j] = 0;
            else
                dp[0][j] = dp[0][j - 1];
        }
        for(int i = 1; i < height; i++){
            if(obstacleGrid[i][0] == 1)
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i - 1][0];
        }
        for(int i = 1; i < height; i++){
            for(int j = 1; j < width; j++){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[height - 1][width - 1];
    }
};
// @lc code=end

