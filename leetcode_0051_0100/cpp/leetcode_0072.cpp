/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int x = word1.size(), y = word2.size();//x-->y
        vector<vector<int>> dp(x + 1, vector<int>(y + 1));
        for(int i = 0; i <= x; i++)
            dp[i][0] = i;
        for(int j = 0; j <= y; j++)
            dp[0][j] = j;
        for(int i = 1; i <= x; i++){
            for(int j = 1; j <= y; j++){
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            }
        }
        return dp[x][y];
    }
};
// @lc code=end

