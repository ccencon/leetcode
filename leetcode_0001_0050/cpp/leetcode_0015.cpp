/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        map<int, int> positive_nums;
        int min_pst_idx = nums.size();
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] > 0){
                positive_nums[nums[i]]++;
                min_pst_idx = i;
            }
            else
                break;
        }
        for(int i = 0; i < min_pst_idx; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j = i + 1; j < (int)nums.size() - 1; j++){
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int num = -(nums[i] + nums[j]);
                if(num < nums[j])
                    break;
                auto it = positive_nums.find(num);
                if(it == positive_nums.end())
                    continue;
                if(num == nums[j]){
                    if(it->second >= 2)
                        ret.push_back({nums[i], num, num});
                    break;
                }
                ret.push_back({nums[i], nums[j], num});
            }
        }//最后特殊处理一下连续3个0的情况
        if(min_pst_idx >= 3 && !nums[min_pst_idx - 1] && !nums[min_pst_idx - 2] && !nums[min_pst_idx - 3])
            ret.push_back({0, 0, 0});
        return ret;
    }
};
// @lc code=end

