/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int right = matrix[0].size() - 1;
        for(const auto& v : matrix){
            if(v[right] == target)
                return true;
            if(target > v[right])
                continue;
            int left = 0; right--;
            while(left <= right){
                int mid = (left + right) / 2;
                if(mid == left)
                    return v[left] == target || v[right] == target;
                if(v[mid] == target)
                    return true;
                if(v[mid] < target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            break;
        }
        return false;
    }
};
// @lc code=end

