/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size(), idx = 1;
        vector<int> arr(len, 1);
        while(idx < len){
            if(ratings[idx] > ratings[idx - 1]){
                int left = idx++;
                while(idx < len && ratings[idx] > ratings[idx - 1])
                    idx++;
                for(int v = 2; left < idx; left++, v++)
                    arr[left] = v;
            }
            else if(ratings[idx] < ratings[idx - 1]){
                int left = idx++ - 1;
                while(idx < len && ratings[idx] < ratings[idx - 1])
                    idx++;
                for(int i = idx - 2, v = 2; i > left; i--, v++)
                    arr[i] = v;
                arr[left] = max(arr[left], arr[left + 1] + 1);
            }
            else
                idx++;
        }
        return accumulate(arr.begin(), arr.end(), 0);
    }
};
// @lc code=end

