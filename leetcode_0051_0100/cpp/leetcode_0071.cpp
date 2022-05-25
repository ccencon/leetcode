/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        string ans(path.length(), '/');
        int index = 0, i = 1, pl = path.length();
        while(i < pl){
            if(path[i] == '/'){
                i++;
                continue;
            }
            if(path[i] == '.'){
                if(i + 1 == pl || path[i + 1] == '/'){
                    i += 2;
                    continue;
                }
                if(path[i + 1] == '.' && (i + 2 == pl || path[i + 2] == '/')){
                    while(index > 1 && ans[index - 1] != '/')
                        index--;
                    index = max(0, index - 1);
                    i += 3;
                    continue;
                }
            }
            ans[index++] = '/';
            while(i < pl && path[i] != '/')
                ans[index++] = path[i++];
            i++;
        }
        ans.resize(index > 1 ? index : 1);
        return ans;
    }
};
// @lc code=end

