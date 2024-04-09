/*
 * @lc app=leetcode.cn id=157 lang=cpp
 *
 * [157] 用 Read4 读取 N 个字符
 */

// @lc code=start
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int i = 4;
        char tmp[4];
        for(; i <= n; i += 4){
            int count = read4(tmp);
            memcpy(buf + i - 4, tmp, count);
            if(count < 4)
                return i - 4 + count;
        }
        if(n < i && n > i - 4){
            int count = read4(tmp);
            if(count >= n - i + 4)
                memcpy(buf + i - 4, tmp, n - i + 4);
            else{
                memcpy(buf + i - 4, tmp, count);
                return i - 4 + count;
            }
        }
        return n;
    }
};
// @lc code=end

