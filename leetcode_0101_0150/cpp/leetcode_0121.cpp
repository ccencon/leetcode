/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 0, diff = 0;
        while(++right < prices.size()){
            if(prices[right] > prices[left])
                diff = max(diff, prices[right] - prices[left]);
            else
                left = right;
        }
        return diff;
    }
};
// @lc code=end

