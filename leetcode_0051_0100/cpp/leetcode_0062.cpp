/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        unsigned long long min_mn = min(m, n), ans = 1;
        for(int x = m + n - min_mn, y = 1; y < min_mn; x++, y++)
            ans = ans * x / y;//y从1开始连续递增，不会存在除不尽的情况
        return ans;
    }
};
// @lc code=end

