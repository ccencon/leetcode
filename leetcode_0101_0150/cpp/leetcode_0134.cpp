/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int max_D = 0, D = 0, idx = 0, len = gas.size();
        for(int i = 0; i < len; i++){
            D += gas[i] - cost[i];
            if(max_D > D){
                max_D = D;
                idx = i + 1;
            }
        }
        return D < 0 ? -1 : idx;
    }
};
// @lc code=end

