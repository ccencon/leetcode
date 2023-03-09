/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1); ans[0] = 1;
        for(int i = 1; i <= rowIndex / 2; i++){
            unsigned long long sum = 1;
            for(int j = 1; j <= i; j++)
                sum = sum * (rowIndex - i + j) / j;
            ans[i] = sum;
        }
        for(int i = rowIndex / 2 + 1; i <= rowIndex; i++)
            ans[i] = ans[rowIndex - i];
        return ans;
    }
};
// @lc code=end

