/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
//1-
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         vector<vector<int>> mem(4, vector<int>(prices.size()));
//         vector<vector<bool>> flag(4, vector<bool>(prices.size(), false));
//         function<int(int, int)> helper = [&](int status, int index){
//             if(index >= prices.size() || status >= 4)
//                 return 0;
//             if(flag[status][index])
//                 return mem[status][index];
//             int v1 = helper(status, index + 1);
//             int v2 = status % 2 == 0 ? helper(status + 1, index + 1) - prices[index] :\
//                 prices[index] + helper(status + 1, index + 1);
//             mem[status][index] = max(v1, v2);
//             flag[status][index] = true;
//             return mem[status][index];
//         };
//         return helper(0, 0);
//     }
// };
//2-官方题解
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};
// @lc code=end

