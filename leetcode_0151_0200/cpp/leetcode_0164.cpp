/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
#include <vector>
#include <array>
using namespace std;
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        vector<int> dup(nums.size());
        array<int, 16> cnt{};
        vector<int>* p1 = &nums, *p2 = &dup;
        for(int off = 0; off < 32; off += 4){
            for(int v : *p1)
                cnt[(v >> off) & 0xF]++;
            for(int i = 1; i < cnt.size(); i++)
                cnt[i] += cnt[i - 1];
            for(int i = p1->size() - 1; i >= 0; i--)
                (*p2)[--cnt[((*p1)[i] >> off) & 0xF]] = (*p1)[i];
            swap(p1, p2);
            fill(cnt.begin(), cnt.end(), 0);
        }
        int ret = (*p1)[1] - (*p1)[0];
        for(int i = 1; i < p1->size(); i++)
            ret = max(ret, (*p1)[i] - (*p1)[i - 1]);
        return ret;
    }
};
// @lc code=end

