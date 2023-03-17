/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <unordered_map>
#include <functional>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> union_set(nums.size());
        iota(union_set.begin(), union_set.end(), 0);
        unordered_map<int, int> mv2i;
        function<int(int)> union_root = [&](int idx){
            return idx == union_set[idx] ? idx : (union_set[idx] = union_root(union_set[idx]));
        };
        function<void(int, int)> union_merge = [&](int idx1, int idx2){
            union_set[union_root(idx1)] = union_set[union_root(idx2)];
        };
        for(int i = 0; i < (int)nums.size(); i++){
            if(mv2i.find(nums[i]) != mv2i.end())
                continue;
            mv2i[nums[i]] = i;
            unordered_map<int, int>::const_iterator it = mv2i.find(nums[i] - 1);
            if(it != mv2i.end())
                union_merge(it->second, i);
            it = mv2i.find(nums[i] + 1);
            if(it != mv2i.end())
                union_merge(i, it->second);
        }
        int ans = 0;
        for(int i = 0; i < (int)nums.size(); i++)
            ans = max(ans, nums[union_root(i)] - nums[i] + 1);
        return ans;
    }
};
// @lc code=end

