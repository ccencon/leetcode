# leetcode_0151_0200
|order|question|cpp link|
|:-|:-|:-|
|[0151](#0151)|[颠倒字符串中的单词](#0151)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0151.cpp)|

#### <span id=0151>[151] 颠倒字符串中的单词</span>
题目链接：[https://leetcode-cn.com/problems/reverse-words-in-a-string](https://leetcode-cn.com/problems/reverse-words-in-a-string)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0151.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0151.cpp)  
运行时间：beats 72.08%  
解题思路：为实现进阶要求的 $O(1)$ 空间复杂度，可以事先将字符串进行一次翻转，然后再逐个翻转每个单词；设定left和right两个指针从0开始，right往后跳过空格寻找单词，将单词拷贝到从left开始的地方，翻转并添加空格；最后left的大小减一即为新字符串的长度
