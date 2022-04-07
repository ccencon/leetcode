# leetcode_0001_0050
|order|question|cpp link|
|:-|:-|:-|
|[0001](#0001)|[两数之和](#0001)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0001.cpp)|
|[0002](#0002)|[两数相加](#0002)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0002.cpp)|
|[0003](#0003)|[无重复字符的最长子串](#0003)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0003.cpp)|
|[0004](#0004)|[寻找两个正序数组的中位数](#0004)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0004.cpp)|
|[0005](#0005)|[最长回文子串](#0005)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0005.cpp)|
|[0006](#0006)|[z-字形变换](#0006)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0006.cpp)|
|[0007](#0007)|[整数反转](#0007)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0007.cpp)|
|[0008](#0008)|[字符串转换整数-atoi](#0008)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0008.cpp)|
|[0009](#0009)|[回文数](#0009)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0009.cpp)|
|[0010](#0010)|[正则表达式匹配](#0010)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0010.cpp)|
|[0011](#0011)|[盛最多水的容器](#0011)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0011.cpp)|
|[0012](#0012)|[整数转罗马数字](#0012)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0012.cpp)|
|[0013](#0013)|[罗马数字转整数](#0013)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0013.cpp)|

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
解题思路：苦思一个小时，结果第一道hard就翻车；题目限定了时间复杂度为O(log(m+n))，所以不能开辟额外空间对数组进行排序；最终还是看了最多投票答案，思路是计算出中位数偏移位置f之后，分别向两个数组分摊这个偏移，假设为f1、f2，因为两个数组是升序排列，所以如果nums1[f1]小于nums2[f2]，那nums1数组中前f1位就可以确定小于中位数，记录这个f1，并将f-f1，重复判断，直至f等于1（如果f1或f2达到对应数组长度，返回另一个数组剩余f的偏移即可）；题解是递归实现，思路明确之后非递归的实现也比较容易写，本题解答便是同样思路的非递归实现；这题可以进一步抽象，求n个数组，总长度为N的中位数，同样可以按照这个思路求解，时间复杂度为O(log_n N)
#### <span id=0005>[5] 最长回文子串</span>
题目链接：[https://leetcode-cn.com/problems/longest-palindromic-substring](https://leetcode-cn.com/problems/longest-palindromic-substring)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0005.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0005.cpp)  
解题思路：设定一个基准点，然后判断两边字符是否相等，刷新最长回文子串；如果左边字符与基准字符相等，再执行同样的操作，时间复杂度为O(n^2)，可以优化的点是当最长回文子串长度大于基准点与最尾字符距离差值的两倍时，可以提前跳出循环，结束判断
#### <span id=0006>[6] z-字形变换</span>
题目链接：[https://leetcode-cn.com/problems/zigzag-conversion](https://leetcode-cn.com/problems/zigzag-conversion)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0006.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0006.cpp)  
解题思路：最直观的方法就是设定个数与输入行数相等的字符串数组，对原字符串进行遍历的时候根据下标将字符赋值到不同的字符串数组中，最后拼接返回，时间复杂度为O(n)，不过这种方法部分字符在最后进行了无意义拷贝。可以对Z-字形排列进行找规律，比如输入行数为5，那么第1行和第5行字符每次步进长度为（5-1）\*2=8，中间第2行每次步进长度分别为（5-2）\*2=6，8-6=2循环...根据这种规律，设定一个新字符串并对行数进行遍历，将每一行的字符根据步进长度依次复制到新字符串中，最后返回；时间复杂度与第一种方法一致，但是部分字符却少了一次内存拷贝
#### <span id=0007>[7] 整数反转</span>
题目链接：[https://leetcode-cn.com/problems/reverse-integer](https://leetcode-cn.com/problems/reverse-integer)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0007.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0007.cpp)  
解题思路：一开始以为是与或非的位运算问题，想了半天感觉没方案就采用了循环除法，结果runtime只打败了42.21%的提交，去看题解结果思路都是一样的，难道是因为部分提交直接标明了INT_MAN和INT_MIN的前后部分数值导致了runtime的差异？于是把代码里面对INT_MAN和INT_MIN的计算去掉，写定了具体数值，再次submit，runtime打败了100%的提交...
#### <span id=0008>[8] 字符串转换整数-atoi</span>
题目链接：[https://leetcode-cn.com/problems/string-to-integer-atoi](https://leetcode-cn.com/problems/string-to-integer-atoi)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0008.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0008.cpp)  
解题思路：过滤掉前置空格后判断符号位，设置factor为1或者-1，将factor乘以每次读取的字符与'0'的ASCII码差值，然后累加，直至字符串结束或者遇到非数字字符，累加后若累加数大于等于INT_MAX，结束返回INT_MAX，INT_MIN同理
#### <span id=0009>[9] 回文数</span>
题目链接：[https://leetcode-cn.com/problems/palindrome-number](https://leetcode-cn.com/problems/palindrome-number)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0009.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0009.cpp)  
解题思路：将输入整数拆分成前后两部分判断是否相等，后部分通过累加累乘反转，最后判断前后两部分是否相等或去掉中间数之后是否相等即可；值得注意的是形如122100这种最末尾一位有0的，需要提前判断返回false，不然按照这种思路会返回true
#### <span id=0010>[10] 正则表达式匹配</span>
题目链接：[https://leetcode-cn.com/problems/regular-expression-matching](https://leetcode-cn.com/problems/regular-expression-matching)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0010.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0010.cpp)  
解题思路：runtime打败了9.几%的提交...解答采用了递归的方法，对比了一下官网递归题解的思路，发现有许多值得优化的地方，先mark一下自己的思路：题目中的正则匹配可以分为两种，一种是带\*匹配，一种是单个字符匹配。单个字符匹配比较好处理，步进判断即可；带\*匹配是匹配0个或多个，当遇到带\*匹配时，需要递归判断s中的剩余字符（已匹配索引一步步往后移）和p中剩余匹配字符，当成功匹配一次时返回true，如果都没成功匹配返回false  

官方的递归思路与上述思路大体一致，主要差别体现在实现技巧上，比如官解最开始的返回点是判断p是否为空，是则返回s是否为空，但上述解答中传入p就不允许为空，这就使代码里面会p的长度进行较多的判断，逻辑也变得冗余，代码不够简洁清晰  

另外一种经典解法就是DP求解，设定数组dp[i][j]，表示s中的前i个字符能够被p的前j个字符匹配，i从0开始，迭代计算当前i与j（0-p的长度）能否匹配；在官方DP解答中，为了使状态能够进行顺利迁移，对i和j进行了特别处理，使p对空字符串进行了一次正则匹配，但这似乎也使大部分人的理解直接撞墙，也包括我自己；在真正搞懂DP的思路之后，可以对官方题解进行思路优化。使i，j从0开始，不大于对应字符串长度，在明确初始状态之后，还需要明确i=0，j≠0时的状态迁移，这也是跟目前其他题解最大的不同，具体看代码；时间复杂度O(ij)，与递归解法一致，但多次提交的runtime都达到了0ms
#### <span id=0011>[11] 盛最多水的容器</span>
题目链接：[https://leetcode-cn.com/problems/container-with-most-water](https://leetcode-cn.com/problems/container-with-most-water)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0011.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0011.cpp)  
解题思路：从两边向中间靠拢计算，取最小高度\*宽度并刷新最大面积，如果左边等于最小高度，左边向中间靠拢，否则右边向中间靠拢；时间复杂度O(n)，原以为达到了最优解法，结果还是有可以优化的地方：向中间靠拢时判断新坐标对应的值是否小于等于最小高度，是则继续执行靠拢操作跳过不必要的面积计算
#### <span id=0012>[12] 整数转罗马数字</span>
题目链接：[https://leetcode-cn.com/problems/integer-to-roman](https://leetcode-cn.com/problems/integer-to-roman)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0012.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0012.cpp)  
解题思路：提交之后看到runtime不够理想点开最多投票答案，好家伙，直接用列表保存了每一位对应的罗马数字，这也让我想起以前写过获取位图第一个为0的高位索引的代码，采用的也是类似的方法，256个char保存了出现0的最高位索引。当前思路：分析得知，当出现4，5，9时需要特殊处理添加左边罗马数字，然后剩下高位小于4的数，再循环添加，所以可以写成两个函数依次调用，即传入高位因子和对应罗马数字分别处理这两种情况
#### <span id=0013>[13] 罗马数字转整数</span>
题目链接：[https://leetcode-cn.com/problems/roman-to-integer](https://leetcode-cn.com/problems/roman-to-integer)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0013.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0001_0050/cpp/leetcode_0013.cpp)  
解题思路：类似于上一道题，可以用哈希表保存每个罗马字符对应的数值；对罗马字符串进行遍历，累加每一位数，特殊的情况是，遇到紧挨的罗马数字且左边比右边小时，需要减掉左边数的两倍
