/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1, idx = n - 1;
        for(; idx >= 0; idx--){
            fact *= n - idx;
            if(fact >= k)
                break;
        }
        string ans(n, '1');
        unsigned int flag = 0;
        auto next_number = [&](int pos){
            for(int i = pos; i < n; i++)
                if(!(flag & (1 << i)))
                    return i + 1;
            return 0;
        };
        for(int i = 0; i < idx; i++){
            ans[i] = i + '1';
            flag |= 1 << i;
        }
        for(; idx < n - 1; idx++){
            if(k <= 1)
                break;
            fact /= (n - idx);
            int num = next_number(0);
            while(k > fact){
                k -= fact;
                num = next_number(num);
            }
            ans[idx] = num + '0';
            flag |= 1 << (num - 1);
        }
        int num = next_number(0);
        for(; idx < n; idx++){
            ans[idx] = num + '0';
            flag |= 1 << (num - 1);
            num = next_number(num);
        }
        return ans;
    }
};
// @lc code=end

