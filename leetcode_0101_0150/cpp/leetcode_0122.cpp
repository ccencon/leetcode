/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int right = 0, diff = 0;
        while(++right < prices.size()){
            if(prices[right] > prices[right - 1])
                diff += prices[right] - prices[right - 1];
        }
        return diff;
    }
};
// @lc code=end

