/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
#include <string>
#include <vector>
#include <functional>
using namespace std;
//1-
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int sl = s.size(), tl = t.size();
//         if(sl == 0 || tl == 0)
//             return 0;
//         vector<int> idxs;
//         vector<vector<int>> mem(sl, vector<int>(tl, -1));
//         int count = 0, is = 0, it = 0;
//         while(true){
//             if(mem[is][it] != -1){
//                 count += mem[is][it];
//                 for(int i = idxs.size() - 1; i > 0; i--){
//                     for(int j = idxs[i - 1] + 1; j <= idxs[i]; j++){
//                         if(mem[j][i] == -1)
//                             mem[j][i] = mem[is][it];
//                         else
//                             mem[j][i] += mem[is][it];
//                     }
//                 }
//                 is = idxs.back() + 1;
//                 idxs.resize(idxs.size() - 1);
//                 it--;
//                 continue;
//             }
//             if(s[is] == t[it]){
//                 idxs.emplace_back(is);
//                 is++; it++;
//             }
//             else{
//                 is++;
//             }
//             if(it == tl){
//                 count++; it--;
//                 for(int i = idxs.size() - 1; i > 0; i--){
//                     for(int j = idxs[i - 1] + 1; j <= idxs[i]; j++){
//                         if(mem[j][i] == -1)
//                             mem[j][i] = 1;
//                         else
//                             mem[j][i] += 1;
//                     }
//                 }
//                 idxs.resize(tl - 1);
//             }
//             while(sl - is < tl - it){
//                 if(idxs.empty())
//                     return count;
//                 for(int i = idxs.size() - 1; i > 0; i--){
//                     for(int j = idxs[i - 1] + 1; j <= idxs[i]; j++){
//                         if(mem[j][i] == -1)
//                             mem[j][i] = 0;
//                     }
//                 }
//                 is = idxs.back() + 1;
//                 idxs.resize(idxs.size() - 1);
//                 it--;
//             }
//         }
//     }
// };
//2-
class Solution {
public:
    int numDistinct(string s, string t) {
        int sl = s.size(), tl = t.size();
        vector<vector<int>> mem(sl, vector<int>(tl, -1));
        function<int(int, int)> helper = [&](int is, int it){
            if(sl - is < tl - it)
                return 0;
            if(it >= tl)
                return 1;
            if(mem[is][it] != -1)
                return mem[is][it];
            if(s[is] == t[it])
                mem[is][it] = helper(is + 1, it + 1) + helper(is + 1, it);
            else
                mem[is][it] = helper(is + 1, it);
            return mem[is][it];
        };
        return helper(0, 0);
    }
};
// @lc code=end

