/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = min(x / 2 + 1, 46340), mid;
        while(left <= right){
            mid = (left + right) / 2;
            if(mid == left)
                return right * right > x ? left : right;
            int sq = mid * mid;
            if(sq == x)
                return mid;
            else if(sq < x)
                left = mid;
            else
                right = mid - 1;
        }
        return mid;
    }
};
// @lc code=end

