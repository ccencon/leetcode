/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int al = a.length(), bl = b.length(), minl, maxl, overflow = 0;
        string* pMax, *pMin;
        if(al > bl){
            minl = bl;
            pMax = &a;
            pMin = &b;
        }
        else{
            minl = al;
            pMax = &b;
            pMin = &a;
        }
        maxl = al + bl - minl;
        for(int i = minl - 1, j = maxl - 1; i >= 0; i--, j--){
            overflow += (*pMin)[i] - '0' + (*pMax)[j] - '0';
            (*pMax)[j] = overflow % 2 + '0';
            overflow >>= 1;
        }
        if(overflow == 0)
            return *pMax;
        for(int j = maxl - minl - 1; j >= 0; j--){
            overflow += (*pMax)[j] - '0';
            (*pMax)[j] = overflow % 2 + '0';
            overflow >>= 1;
        }
        if(overflow == 1)
            pMax->insert(pMax->begin(), '1');
        return *pMax;
    }
};
// @lc code=end

