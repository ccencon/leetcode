/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		int flag[3] = { 1, 1, 1 }, sl = s.size();
		vector<string> ans; string tmp;
		auto isValidIpInteger = [&s, sl](int pos, int length){
			if (pos + length > sl)
				return false;
			if (length > 1 && s[pos] == '0')
				return false;
			unsigned long long t = 0;
			for (int i = 0; i < length; i++)
				t = t * 10 + s[pos + i] - '0';
			return t <= 255;
		};
		int traceIdx = 0, pos = 0;
		while (traceIdx >= 0){
			for (; traceIdx < 3; traceIdx++){
				if (!isValidIpInteger(pos, flag[traceIdx])){
					flag[traceIdx] = 1;
					break;
				}
				tmp += s.substr(pos, flag[traceIdx]);
				tmp.push_back('.');
				pos += flag[traceIdx];
			}
			if (traceIdx == 3){
				if (pos < sl && isValidIpInteger(pos, sl - pos)){
					tmp += s.substr(pos, sl - pos);
					ans.emplace_back(tmp);
					tmp.resize(pos + 3);
				}
			}
			while (--traceIdx >= 0){
				tmp.resize(tmp.size() - 1 - flag[traceIdx]);
				pos -= flag[traceIdx];
				if (flag[traceIdx] < 3){
					flag[traceIdx]++;
					break;
				}
				flag[traceIdx] = 1;
			}
		}
		return ans;
	}
};
// @lc code=end

