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
// class Solution {
// public:
//     void GetSteps(string& m, vector<int>& step)
//     {
//         int range = 0;
//         bool rec[256];
//         memset(rec, 0, sizeof(rec));
//         for(int i = 0; i < m.size(); i++){
//             unsigned char c = m[i];
//             if(rec[c]){
//                 int idx = (i + 1) % range;
//                 if(idx == 0)
//                     idx = range;
//                 if(c != m[idx - 1]){
//                     for(range++; range <= i + 1; range++){
//                         int mod = (i + 1) % range, tmp = 0;
//                         if(mod == 0)
//                             mod = range;
//                         for(; tmp < mod; tmp++)
//                             if(m[i - tmp] != m[tmp])
//                                 break;
//                         if(tmp == mod){
//                             step[i] = range;
//                             break;
//                         }
//                     }
//                 }
//                 else
//                     step[i] = range;
//             }
//             else{
//                 step[i] = i + 1;
//                 range = i + 1;
//                 rec[c] = true;
//             }
//         }
//     }
//     int strStr(string haystack, string needle) {
//         int ms = needle.size(), ns = haystack.size();
//         if(!ms)
//             return 0;
//         vector<int> step(ms);
//         GetSteps(needle, step);
//         int j = 0, i = 0;
//         while(i < ns && j < ms){
//             if(haystack[i] != needle[j]){
//                 if(j)
//                     j -= step[j - 1];
//                 else
//                     i++;
//             }
//             else{
//                 j++;
//                 i++;
//             }
//         }
//         if(j == ms)
//             return i - j;
//         return -1;
//     }
// };
class Solution {
public:
	void Next(const string& needle, vector<int>& next){
		int i = 2, j = 0, Nl = needle.size(); next[1] = 0;
		while (i < Nl){
			if (needle[i - 1] == needle[j])
				next[i++] = ++j;
			else if (j == 0)
				next[i++] = 0;
			else
				j = next[j];
		}
	}
	int strStr(string haystack, string needle){
		int Nl = needle.size();
		if (!Nl)
			return 0;
		vector<int> next(Nl + 1);
		Next(needle, next);
		int i = 0, j = 0, Hl = haystack.size();
		while (i < Hl && j < Nl){
			if (haystack[i] == needle[j]){
				i++; j++;
			}
			else if (j == 0)
				i++;
			else
				j = next[j];
		}
		if (j >= Nl)
			return i - j;
		return -1;
	}
};
// @lc code=end

