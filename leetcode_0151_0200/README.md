# leetcode_0151_0200
|order|question|cpp link|
|:-|:-|:-|
|[0151](#0151)|[颠倒字符串中的单词](#0151)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0151.cpp)|
|[0152](#0152)|[乘积最大子数组](#0152)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0152.cpp)|
|[0153](#0153)|[寻找旋转排序数组中的最小值](#0153)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0153.cpp)|

#### <span id=0151>[151] 颠倒字符串中的单词</span>
题目链接：[https://leetcode-cn.com/problems/reverse-words-in-a-string](https://leetcode-cn.com/problems/reverse-words-in-a-string)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0151.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0151.cpp)  
运行时间：beats 72.08%  
解题思路：为实现进阶要求的 $O(1)$ 空间复杂度，可以事先将字符串进行一次翻转，然后再逐个翻转每个单词；设定 $left$ 和 $right$ 两个指针从0开始， $right$ 往后跳过空格寻找单词，将单词拷贝到从 $left$ 开始的地方，翻转并添加空格；最后 $left$ 的大小减一即为新字符串的长度
#### <span id=0152>[152] 乘积最大子数组</span>
题目链接：[https://leetcode-cn.com/problems/maximum-product-subarray](https://leetcode-cn.com/problems/maximum-product-subarray)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0152.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0152.cpp)  
运行时间：beats 94.16%  
解题思路：看完题目后，潜意识里就觉得应该往动态规划的方向思考，于是满怀信心提交一版，果断gg；原因在于设定 $dp[i]$ 记录以下标 $i$ 结尾的最大子数组乘积，但没考虑到负数个数为奇数的情况下，最大乘积的子数组不一定是从第一个负数开始。苦思良久突然发现，解法没必要想的那么复杂，只需要遍历数组的过程中，记录数组的总乘积，当这个乘积为正数时，那么它一定是最大的，如果乘积为负数，则说明数组中有奇数个负数，只需将当前总乘积除以第一个奇数位置的总乘积，便得出以当前位置为结尾的最大子数组乘积。由于包含0的子数组乘积永远是0，所以在遍历过程中可以将数组以0为边界进行分割，当遇到0时，跳过，并重置总乘积和第一个负数的位置
#### <span id=0153>[153] 寻找旋转排序数组中的最小值</span>
题目链接：[https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0153.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0153.cpp)  
运行时间：beats 100%  
解题思路：这应该算作一道重复题，与[[33] 搜索旋转排序数组](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050#0033)本质上是一样的；解决思路就是进行二分查找，因为其旋转特性，当 $nums[mid]$ 比 $nums[right]$ 大时，说明最小数位于区间 $[mid+1, right]$ ，否则就是位于 $[left, mid]$
