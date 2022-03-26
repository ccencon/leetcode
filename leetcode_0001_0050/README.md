# leetcode_0001_0050
|order|question|cpp link|
|:-|:-|:-|
|[0001](#0001)|[两数之和](#0001)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0001.cpp)|
|[0002](#0002)|[两数相加](#0002)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0002.cpp)|
|[0003](#0003)|[无重复字符的最长子串](#0003)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0003.cpp)|
|[0004](#0004)|[寻找两个正序数组的中位数](#0004)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0004.cpp)|

#### <span id=0001>[1] 两数之和</span>
题目链接：[https://leetcode-cn.com/problems/two-sum](https://leetcode-cn.com/problems/two-sum)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0001.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0001.cpp)  
解题思路：这题思路比较明显，用哈希表存储，key存储值，value存储索引，遍历的时候判断差值是否也在哈希表中，是则返回索引；但具体实现的时候先遍历了一次数组，把值加入到哈希表中，再进行差值判断，技巧性较差。在思路正确的情况下，实现好坏往往都是取决于实现技巧
#### <span id=0002>[2] 两数相加</span>
题目链接：[https://leetcode-cn.com/problems/add-two-numbers](https://leetcode-cn.com/problems/add-two-numbers)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0002.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0002.cpp)  
解题思路：链表的大数相加，设定一个初始为0的溢出位，每次循环依次与对应链表位相加，直至加完所有位数和溢出位为0即可
#### <span id=0003>[3] 无重复字符的最长子串</span>
题目链接：[https://leetcode-cn.com/problems/longest-substring-without-repeating-characters](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0003.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0003.cpp)  
解题思路：解答方式不是最优解，用哈希表记录已遍历的字符和对应下标，遇到新字符时若哈希表已经存在对应字符，则计算当前下标与基准下标（初始为0）的差值，如果比已记录的最长长度大，则更新最长长度，然后哈希表弹出基准下标到重复字符下标之间的字符，最后更新基准下标然后进入新的循环；最优解是用容量为256的数组记录遍历字符时出现的最大下标，然后设定一个重复下标I，遍历字符时若当前字符记录的下标大于I，则说明当前字符重复，更新I和最长记录长度；其实当前方法可以借鉴最优解答法，它们最大的不同除了记录的数据结构不一样，就在于当前解答方法遇到重复字符时弹出了重复字符之前的所有字符，这是一个无用功，因为基准下标已记录了重复字符的下标，所以只需在哈希表遇到重复字符时多加一个是否大于基准坐标的判断即可
#### <span id=0004>[4] 寻找两个正序数组的中位数</span>
题目链接：[https://leetcode-cn.com/problems/median-of-two-sorted-arrays](https://leetcode-cn.com/problems/median-of-two-sorted-arrays)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0004.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0004.cpp)  
解题思路：苦思一个小时，结果第一道hard就翻车；题目限定了时间复杂度为O(log(m+n))，所以不能开辟额外空间对数组进行排序；最终还是看了最多投票答案，思路是计算出中位数偏移位置f之后，分别向两个数组分摊这个偏移，假设为f1、f2，因为两个数组是升序排列，所以如果nums1[f1]小于nums2[f2]，那nums1数组中前f1位就可以确定小于中位数，记录这个f1，并将f-f1，重复判断，直至f等于1（如果f1或f2达到对应数组长度，返回另一个数组剩余f的偏移即可）；题解是递归实现，思路明确之后非递归的实现也比较容易写，本题解答便是同样思路的非递归实现
