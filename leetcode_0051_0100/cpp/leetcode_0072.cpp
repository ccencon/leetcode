/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <string>
#include <vector>
#include <functional>
using namespace std;
//dp
// class Solution {
// public:
//     int minDistance(string word1, string word2) {
//         int x = word1.size(), y = word2.size();//x-->y
//         vector<vector<int>> dp(x + 1, vector<int>(y + 1));
//         for(int i = 0; i <= x; i++)
//             dp[i][0] = i;
//         for(int j = 0; j <= y; j++)
//             dp[0][j] = j;
//         for(int i = 1; i <= x; i++){
//             for(int j = 1; j <= y; j++){
//                 if(word1[i - 1] == word2[j - 1])
//                     dp[i][j] = dp[i - 1][j - 1];
//                 else
//                     dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
//             }
//         }
//         return dp[x][y];
//     }
// };
//
//BF
class Solution {
public:
    int minDistance(string word1, string word2) {
        int wl_1 = word1.size(), wl_2 = word2.size();
        vector<vector<int>> disRec(wl_1, vector<int>(wl_2, -1));
        function<int(int, int)> cal_dist = [&](int l1, int l2){
            if(l1 >= wl_1)
                return wl_2 - l2;
            if(l2 >= wl_2)
                return wl_1 - l1;
            int min_dist = disRec[l1][l2];
            if(min_dist != -1)
                return min_dist;
            if(word1[l1] == word2[l2])//不变
                min_dist = cal_dist(l1 + 1, l2 + 1);
            else//分别对应替换，插入(向前)，删除
                min_dist = 1 + min({cal_dist(l1 + 1, l2 + 1), cal_dist(l1, l2 + 1), cal_dist(l1 + 1, l2)});
            disRec[l1][l2] = min_dist;
            return min_dist;
        };
        return cal_dist(0, 0);
    }
};
// @lc code=end

