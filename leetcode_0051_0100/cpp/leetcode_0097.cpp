/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
        if(l1 + l2 != l3)
            return false;
        if(l1 == 0)
            return s2 == s3;
        if(l2 == 0)
            return s1 == s3;
        vector<int> idx2_rec(l2, -1);
        vector<unordered_set<int>> flag(l2, unordered_set<int>{});
        int idx1 = 0, idx2 = 0, idx3 = 0;
        while(idx3 < l3){
            if(idx1 < l1 && s1[idx1] == s3[idx3]){
                idx1++; idx3++;
                continue;
            }
            if(idx2 < l2 && s2[idx2] == s3[idx3]){
                idx2_rec[idx2++] = idx3++;
                if(flag[idx2 - 1].find(idx3) == flag[idx2 - 1].end()){
                    flag[idx2 - 1].insert(idx3);
                    continue;
                }
            }
            while(true){
                if(--idx3 < 0)
                    return false;
                if(idx2 > 0 && idx2_rec[idx2 - 1] == idx3){
                    idx2_rec[--idx2] = -1;
                    continue;
                }
                idx1--;
                if(s2[idx2] != s3[idx3])
                    continue;
                idx2_rec[idx2++] = idx3++;
                break;
            }
        }
        return true;
    }
};
// @lc code=end

