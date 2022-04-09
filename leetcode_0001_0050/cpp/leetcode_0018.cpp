/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int length = nums.size();
        for(int i = 0; i < length - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1])//上一轮已经被枚举完
                continue;
            for(int j = i + 1; j < length - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1])//上一轮已经被枚举完
                    continue;
                int left = j + 1, right = length - 1;
                long long twoNum = nums[i] + nums[j];
                while(left < right){
                    long long num = twoNum + nums[left] + nums[right];
                    if(num > target)
                        right--;
                    else if(num < target)
                        left++;
                    else{//中间可能还存在满足条件的两个数
                        ret.push_back({nums[i], nums[j], nums[left], nums[right]});
                        do{
                            right--;
                        }while(left < right && nums[right] == nums[right + 1]);
                        do{
                            left++;
                        }while(left < right && nums[left] == nums[left - 1]);
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end

