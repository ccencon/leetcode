/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <vector>
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
	void GetTempus(string& m, vector<int>& tempus)
	{
		int T = 1; tempus[0] = 1;
		for (int i = 1; i < m.size(); i++){
			int idx = i % T;
			if (m[i] == m[idx])
				tempus[i] = T;
			else{
				for (T++; T < i + 1; T++){
					int __idx = i % T + 1, tmp = 0;
					for (; tmp < __idx; tmp++){
						if (m[tmp] != m[tmp + T])
							break;
					}
					if (tmp == __idx){
						tempus[i] = T;
						break;
					}
				}
				if (T == i + 1){
					T = i + 1;
					tempus[i] = T;
				}
			}
		}
	}
	int strStr(string haystack, string needle) {
		int ms = needle.size(), ns = haystack.size();
		if (!ms)
			return 0;
		vector<int> tempus(ms);
		GetTempus(needle, tempus);
		int j = 0, i = 0;
		while (i < ns && j < ms){
			if (haystack[i] == needle[j]){
				i++; j++;
			}
			else if (j == 0)
				i++;
			else
				j -= tempus[j - 1];
		}
		if (j >= ms)
			return i - j;
		return -1;
	}
};

// class Solution {
// public:
// 	void Next(const string& needle, vector<int>& next){
// 		int i = 2, j = 0, Nl = needle.size(); next[1] = 0;
// 		while (i < Nl){
// 			if (needle[i - 1] == needle[j])
// 				next[i++] = ++j;
// 			else if (j == 0)
// 				next[i++] = 0;
// 			else
// 				j = next[j];
// 		}
// 	}
// 	int strStr(string haystack, string needle){
// 		int Nl = needle.size();
// 		if (!Nl)
// 			return 0;
// 		vector<int> next(Nl + 1);
// 		Next(needle, next);
// 		int i = 0, j = 0, Hl = haystack.size();
// 		while (i < Hl && j < Nl){
// 			if (haystack[i] == needle[j]){
// 				i++; j++;
// 			}
// 			else if (j == 0)
// 				i++;
// 			else
// 				j = next[j];
// 		}
// 		if (j >= Nl)
// 			return i - j;
// 		return -1;
// 	}
// };
// @lc code=end

