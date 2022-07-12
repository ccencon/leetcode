/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        long long ans = 1;
        for(int i = 1; i <= n; i++)
            ans = ans * (4 * i - 2) / (i + 1);
        return ans;
    }
};
// @lc code=end

