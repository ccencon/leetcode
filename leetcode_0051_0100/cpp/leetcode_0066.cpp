/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int overflow = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            overflow += digits[i];
            digits[i] = overflow % 10;
            overflow /= 10;
            if(overflow == 0)
                return digits;
        }
        digits.insert(digits.begin(), overflow);
        return digits;
    }
};
// @lc code=end

