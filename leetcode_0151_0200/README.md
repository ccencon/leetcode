# leetcode_0151_0200
|order|question|cpp link|
|:-|:-|:-|
|[0151](#0151)|[颠倒字符串中的单词](#0151)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0151.cpp)|
|[0152](#0152)|[乘积最大子数组](#0152)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0152.cpp)|
|[0153](#0153)|[寻找旋转排序数组中的最小值](#0153)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0153.cpp)|
|[0154](#0154)|[寻找旋转排序数组中的最小值-ii](#0154)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0154.cpp)|
|[0155](#0155)|[最小栈](#0155)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0155.cpp)|
|[0160](#0160)|[相交链表](#0160)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0160.cpp)|

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
解题思路：这应该算作一道重复题，与[[33] 搜索旋转排序数组](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050#0033)本质上是一样的；解决思路就是进行二分查找，因为其旋转特性，当 $nums[mid]$ 比 $nums[right]$ 大时，说明最小数位于区间 $[mid+1, right]$ ，否则就是位于 $[left, mid]$ ；另外一点，当 $nums[left]$ 比 $nums[right]$ 小时，说明区间内已经有序， $nums[left]$ 必然是最小数，直接返回即可
#### <span id=0154>[154] 寻找旋转排序数组中的最小值-ii</span>
题目链接：[https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0154.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0154.cpp)  
运行时间：beats 85.03%  
解题思路：这也可以算作一道重复题，对标[[81] 搜索旋转排序数组-ii](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100#0081)；其中与[[153] 寻找旋转排序数组中的最小值](#0153)不同的点在于数组中可能存在重复元素，当数组存在重复元素时，便没法确定区间应该如何进行偏移；如序列 $2 2 2 4 1 2 2$ 和 $2 2 1 4 2 2 2$ ，它们初始的状态都一样，但却有着不用的偏移方向；解决方法也很简单，当左边或右边遇到重复元素时，便往中间靠拢直至没有重复元素，将其转化为第154题的情况
#### <span id=0155>[155] 最小栈</span>
题目链接：[https://leetcode-cn.com/problems/min-stack](https://leetcode-cn.com/problems/min-stack)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0155.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0155.cpp)  
运行时间：beats 42.67%  
解题思路：设定两个栈 $A$ 和 $B$ ，栈 $A$ 用来记录入栈的数，栈 $B$ 用来记录栈 $A$ 当前的最小数。当 $A$ 出栈时， $B$ 同步出栈；当入栈 $A$ 时，将入栈数与当前最小数比较得出新的最小数，将新的最小数入栈 $B$ ；这样使得获取栈 $A$ 的最小值时，直接返回栈 $B$ 的栈顶元素即可

在浏览官方题解的评论中，发现了一种更加巧妙的方法，就是只设立一个栈和一个最小数，这个栈用来记录与最小数的差值，当这个差值为正数时，差值+栈记录=入栈数；当差值为负数时，说明最小值更新，旧最小值-差值=新的最小值，新的最小值同时也是当前入栈数。以这种思路再次实现提交，通过；留意到评论中说这种做法不需要额外空间，这应该是不正确的，虽然少了一个栈，但引入差值的计算会超出原本数据类型的范围，如 $int32$ 的差值，就需要 $int64$ 的栈来保存，这与两个 $int32$ 的栈做法所需空间理论上是一致的
#### <span id=0160>[160] 相交链表</span>
题目链接：[https://leetcode-cn.com/problems/intersection-of-two-linked-lists](https://leetcode-cn.com/problems/intersection-of-two-linked-lists)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0160.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0151_0200/cpp/leetcode_0160.cpp)  
运行时间：beats 51.39%  
解题思路：最简单的解法就是使用哈希表进行结点记录。首先遍历链表 $A$ ，将链表 $A$ 所有结点加入到哈希表中，然后遍历链表 $B$ ，查找其结点是否在哈希表中出现，是的话则是第一个相交结点，返回即可。题目进阶解法要求使用空间复杂度为 $O(1)$ 的解决方案，可以通过转变思路实现。先分别遍历链表 $A$ 和链表 $B$ ，计算出其各自长度，让长的链表先跳过前面几个结点，使两个链表等长，最后同时对两个链表进行遍历，找出第一个相交结点返回即可

官方题解中对于 $O(1)$ 的内存解决方案在本质思想上与上述的方案一致，实现方式却大有不同，官方的实现方式在编码上更加简洁，这里值得记录一下：

1. 设链表 $A$ 的长度为 $m + c$ ，链表 $B$ 的长度为 $n + c$ ，其中 $c$ 为公共部分
2. 同时对链表 $A$ 和链表 $B$ 遍历，每次遍历一个结点，当链表 $A$ 遍历到结尾时，使其从链表 $B$ 开头处重新遍历；当链表 $B$ 遍历到结尾时，使其从链表 $A$ 开头处重新遍历
3. 假设两个链表相交，在转换链表进行遍历时，两个链表必然同时遍历到第一个相交结点，因为这时候走过的路程均为 $m + n + c$（如果 $m = n$ ，在转换前便可同时遍历到第一个相交结点）
4. 如果两个链表不相交，无论 $m$ 是否等于 $n$ ，最终都遍历到空结点结束