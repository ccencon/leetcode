/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n-- == 1)
            return "1";
        string str1("1"), str2;
        string *cur = &str1, *next = &str2;
        while(--n >= 0){
            int length = cur->length(), count = 1;
            char c = cur->operator[](0);
            for(int i = 1; i < length; i++){
                if(cur->at(i) == c)
                    count++;
                else{
                    next->push_back(count + '0');
                    next->push_back(c);
                    count = 1;
                    c = cur->at(i);
                }
            }
            next->push_back(count + '0');
            next->push_back(c);
            swap(cur, next);
            next->clear();
        }
        return *cur;
    }
};
// @lc code=end

