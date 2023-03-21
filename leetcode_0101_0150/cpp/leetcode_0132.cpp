/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
	int minCut(string s) {
		int sl = s.size();
		function<bool(int, int)> isPalindrome = [&](int idx1, int idx2){
			while (idx1 < idx2){
				if (s[idx1] != s[idx2])
					return false;
				idx1++; idx2--;
			}
			return true;
		};
		vector<vector<int>> mem_pld(sl, vector<int>(sl, -1));
		vector<int> mem_times(sl, __INT32_MAX__);
		function<int(int, int)> helper = [&](int idx, int times){
			if(idx >= sl)
				return 0;
			if(mem_times[idx] != __INT32_MAX__)
				return mem_times[idx];
			for(int length = sl - idx; length >= 1; length--){
				if(mem_pld[idx][idx + length - 1] == -1){
					if (isPalindrome(idx, idx + length - 1))
						mem_pld[idx][idx + length - 1] = 1;
					else
						mem_pld[idx][idx + length - 1] = 0;
				}
				if(mem_pld[idx][idx + length - 1] == 0)
					continue;
				mem_times[idx] = min(mem_times[idx], 1 + helper(idx + length, times + 1));
                if(mem_times[idx] == 1)
					break;
			}
			return mem_times[idx];
		};
		return helper(0, 0) - 1;
	}
};
// @lc code=end

