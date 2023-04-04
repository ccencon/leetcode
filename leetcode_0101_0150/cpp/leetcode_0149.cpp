/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int length = points.size();
        if(length < 3)
            return length;
        int count = 0;
        for(int i = 0; i < length - 2; i++){
            for(int j = i + 1; j < length - 1; j++){
                int a = points[i][0] - points[j][0];
                int b = points[i][1] - points[j][1];
                int _c = 2;
                for(int k = j + 1; k < length; k++){
                    if((points[i][1] - points[k][1]) * a == b * (points[i][0] - points[k][0])){
                        _c++;
                    }
                }
                count = max(count, _c);
            }
        }
        return count;
    }
};
// @lc code=end

