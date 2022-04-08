/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long sum = INT_MAX;
        for(int left = 0; left < nums.size() - 2; left++){
            if(left > 0 && nums[left] == nums[left - 1])
                continue;
            int right = nums.size() - 1;
            for(int middle = left + 1; middle < right; middle++){
                if(middle > left + 1 && nums[middle] == nums[middle - 1])
                    continue;
                int num = nums[left] + nums[middle];
                do{
                    int total = num + nums[right];
                    if(abs(target - total) < abs(target - sum))
                        sum = total;
                    if(total > target)
                        right--;
                    else if(total == target)
                        return total;
                    else
                        break;
                }while(right > middle);
            }
        }
        return sum;
    }
};
// @lc code=end

