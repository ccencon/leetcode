/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        string product;
        int oft = 0;
        auto func = [&](int number){
            int flow = 0, idx = oft;
            for(int i = num1.size() - 1; i >= 0; i--){
                int result = (num1[i] - '0') * number + flow;
                if(idx == product.size())
                    product.push_back(result % 10 + '0');
                else{
                    result += product[idx] - '0';
                    product[idx] = result % 10 + '0';
                }
                idx++;
                flow = result / 10;
            }
            if(flow > 0)
                product.push_back(flow + '0');
            oft++;
        };
        for(int i = num2.size() - 1; i >= 0; i--)
            func(num2[i] - '0');
        reverse(product.begin(), product.end());
        return product;
    }
};
// @lc code=end

