/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <climits>
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        if(x >= 0){
            int maxPrior = INT_MAX / 10, maxLast = INT_MAX % 10;
            while(x){
                if(ret > maxPrior || (ret == maxPrior && x % 10 > maxLast))
                    return 0;
                ret = ret * 10 + x % 10;
                x /= 10;
            }
        }
        else{
            int minPrior = INT_MIN / 10, minLast = INT_MIN % 10;
            while(x){
                if(ret < minPrior || (ret == minPrior && x % 10 < minLast))
                    return 0;
                ret = ret * 10 + x % 10;
                x /= 10;
            }
        }
        return ret;
    }
};
// @lc code=end

