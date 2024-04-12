/*
 * @lc app=leetcode.cn id=170 lang=cpp
 *
 * [170] 两数之和 III - 数据结构设计
 */

// @lc code=start
class TwoSum {
    unordered_map<long long int, int> nums;
public:
    TwoSum() {

    }
    
    void add(int number) {
        nums[number]++;
    }
    
    bool find(int value) {
        for(auto [k, v] : nums){
            long long int m = value - k;
            if(m == k){
                if(v > 1)
                    return true;
            }
            else{
                if(nums.count(m) > 0)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

