/*
 * @lc app=leetcode.cn id=158 lang=cpp
 *
 * [158] 用 Read4 读取 N 个字符 II
 */

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    char _internal[4];
    int _idx = 0;
    int _len = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int index = 0;
        while(_len > 0 && index < n){
            buf[index++] = _internal[_idx++];
            _len--;
        }
        while(index < n){
            char tmp[4];
            int count = read4(tmp), wi = 0;
            if(count == 0)
                break;
            for(; wi < count && index < n; wi++, index++)
                buf[index] = tmp[wi];
            if(wi < count){
                _idx = 0; _len = count - wi;
                for(int i = 0; i < _len; i++, wi++)
                    _internal[i] = tmp[wi];
            }
        }
        return min(index, n);
    }
};
// @lc code=end

