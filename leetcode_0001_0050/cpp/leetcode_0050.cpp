/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <cmath>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        double result[32] = {x}, ans = x;
        unsigned int N = abs(n), idx = 1;
        while(idx != 32 && 1 << idx <= N){
            ans *= ans;
            result[idx++] = ans;
        }
        int d = (int)N - (int)(1 << (idx - 1));
        if(d > 0){
            for(int i = 29; i >= 0 && d != 0; i--){//n最大为2^31,经过上一轮计算之后d最大取值不超过2^30
                if(1 << i > d)
                    continue;
                d -= 1 << i;
                ans *= result[i];
            }
        }
        if(n < 0)
            return 1.0f / ans;
        return ans;
    }
};
// @lc code=end

