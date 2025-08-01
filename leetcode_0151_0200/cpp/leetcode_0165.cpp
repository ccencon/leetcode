/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    int getNum(const string& v, int& l)
    {
        if (l >= (int)v.size())
            return 0;
        int num = 0;
        while(++l < (int)v.size() && v[l] != '.')
            num = num * 10 + (v[l] - '0');
        return num;
    }
    int compareVersion(string version1, string version2) {
        int l1 = -1, l2 = -1, num1 = 0, num2 = 0;
        while (l1 < (int)version1.size() || l2 < (int)version2.size()) {
            num1 = getNum(version1, l1);
            num2 = getNum(version2, l2);
            if (num1 != num2)
                return num1 < num2 ? -1 : 1;
        }
        return 0;
    }
};
// @lc code=end

