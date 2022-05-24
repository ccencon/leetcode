# leetcode_0051_0100
|order|question|cpp link|
|:-|:-|:-|
|[0051](#0051)|[n-皇后](#0051)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0051.cpp)|
|[0052](#0052)|[n皇后-ii](#0052)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0052.cpp)|
|[0053](#0053)|[最大子数组和](#0053)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0053.cpp)|
|[0054](#0054)|[螺旋矩阵](#0054)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0054.cpp)|
|[0055](#0055)|[跳跃游戏](#0055)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0055.cpp)|
|[0056](#0056)|[合并区间](#0056)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0056.cpp)|
|[0057](#0057)|[插入区间](#0057)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0057.cpp)|
|[0058](#0058)|[最后一个单词的长度](#0058)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0058.cpp)|
|[0059](#0059)|[螺旋矩阵-ii](#0059)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0059.cpp)|
|[0060](#0060)|[排列序列](#0060)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0060.cpp)|
|[0061](#0061)|[旋转链表](#0061)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0061.cpp)|
|[0062](#0062)|[不同路径](#0062)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0062.cpp)|
|[0063](#0063)|[不同路径-ii](#0063)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0063.cpp)|
|[0064](#0064)|[最小路径和](#0064)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0064.cpp)|
|[0065](#0065)|[有效数字](#0065)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0065.cpp)|
|[0066](#0066)|[加一](#0066)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0066.cpp)|
|[0067](#0067)|[二进制求和](#0067)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0067.cpp)|
|[0068](#0068)|[文本左右对齐](#0068)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0068.cpp)|

#### <span id=0051>[51] n-皇后</span>
题目链接：[https://leetcode-cn.com/problems/n-queens](https://leetcode-cn.com/problems/n-queens)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0051.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0051.cpp)  
运行时间：beats 91.39%  
解题思路：对这类回溯的问题，只要理清如何恢复状态的思路，很容易就可以写出非递归的实现，基本上就是三板斧：  
1. 初始回溯标志，一般为某个索引或索引集合，假定为traceIdx
2. 从traceIdx开始到结束确定一个新的序列，每一个位置确定的状态应该具有次序性，这样回溯的时候可以容易确定下一个状态
3. 回溯traceIdx，从后往前恢复状态，当某个位置有未执行的状态时，转到步骤2执行；若回溯了所有位置，结束执行

这种思路的解答基本上运行时间和内存占用都是击败100%，目前在网上还没见到这种思路的出现，这来源于当初写[有向图](https://github.com/ccencon/structdata#DirectedGraph)输出所有拓扑序列和所有关键路径的做法，目前在所有回溯类的题目中，基本上采用了这种解答方式  

这题的具体做法时，设定数组保存每一行，每一列，每一条斜线的匹配状态，初始trace_i，trace_j，从开始到结束确定第一个结果，然后对trace_i，trace_j进行回溯并恢复状态，并从新的trace_i，trace_j开始确定新的结果
#### <span id=0052>[52] n皇后-ii</span>
题目链接：[https://leetcode-cn.com/problems/n-queens-ii](https://leetcode-cn.com/problems/n-queens-ii)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0052.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0052.cpp)  
运行时间：beats 100%  
解题思路：[n-皇后](#0051)一样的做法，只是将返回字符串换成了返回个数，本质上没有变化
#### <span id=0053>[53] 最大子数组和</span>
题目链接：[https://leetcode-cn.com/problems/maximum-subarray](https://leetcode-cn.com/problems/maximum-subarray)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0053.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0053.cpp)  
运行时间：beats 71.26%  
解题思路：设定prev记录以当前位置结束的最大子数组和，ans记录最大子数组和，遍历到某个pos时，如果prev + nums[pos] < nums[pos]，则prev = nums[pos]，否则prev = prev + nums[pos]，然后刷新ans
#### <span id=0054>[54] 螺旋矩阵</span>
题目链接：[https://leetcode-cn.com/problems/spiral-matrix](https://leetcode-cn.com/problems/spiral-matrix)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0054.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0054.cpp)  
运行时间：beats 100%  
解题思路：哀过程之多艰，这道中等题足足花费了两天的零碎时间。如果按照一般套路来做的话，这道题其实可以归纳为简单题，具体有两种做法：一种是给螺旋轨迹设定一个运动规则，右→下→左→上，即每运动到一个点，便依次判断右下左上是否已经到达过，选出下一个未到达过的点，直至所有点均与到达，但这种方式会存在较多分支判断，可以采用另外一种方法；另外一种方法是模拟旋转路径，按照运动轨迹一层一层地遍历，先往右走，遇到边界往下走，再然后往左走，最后往上走  

在开始码代码之前，脑海里偏向的是第二种做法，但同时也产生了一个疑问，对于m*n阶矩阵，无论这两种的哪一种解答方式，cpu cache命中率都不高，因为不是顺序遍历，而且在已知m，n大小的情况下，矩阵中的每一对下标应该都能确定在answer中的索引值，那应该如何将下标对进行转换，使得能够以顺序遍历矩阵的方式解答这道题？作为一个极容易为想法而纠结的人，也由此开始了多艰的推导之旅  

> 因为索引值的规律性，第一个想法肯定是希望能够找到一个数学方程式进行统一的下标转换，即$i=f(x,y)$，在推导好一会之后发现，螺旋的特性必然要涉及到复杂的三角函数，作为一个数学渣，最后只能不甘心的放弃了这个做法；那既然统一函数不行，那分段函数呢？通过把(x,y)分为上右和左下两部分，因为这两部分的(x,y)跟i存在线性关系，不过这个推导也放弃了，因为某层的计算需要依赖上一层的状态，这样实在太过复杂  

> 第二个想法是将矩阵中每一行进行分段处理，在手动列出几种不同形式的矩阵分布后，可以发现每一行i的规律，中间i是以递增的形式，而左右两边则是以某种差值的形式进行增加或者减少，这需要确定每一对(x,y)位于螺旋中的第几层，确定i是递增还是以差值进行增加或减少的方式，这差值也比较容易计算出来，但由于不好处理矩阵左边和下边两部分，这个想法也以失败告终  

> 虽然上面几个想法行不通（应该说实现太过复杂），但也给最终的实现方式提供了基础。具体做法是，遍历到某个位置时，首先确定当前(x,y)位于螺旋的层数，那么转换后的索引值i=外层点数+位于当前层的第几个点；每一层的外层点数都可以事先计算出来，除了最里层（差8个或7个），每一层与外层必然都是差了8个点，然后再判断(x,y)是位于右上还是左下部分，即通过分段确定坐标对位于当前层的第几个点，从而计算出i值；至于矩阵中左边和下边两部分，可以将(x,y)转换为关于x轴或y轴对称的坐标点进行判断（矩阵关于原点对称）

过程是艰辛的，结果是喜悦的，网上都是清一色的push_back或append，这的确值得花文字记录一下
#### <span id=0055>[55] 跳跃游戏</span>
题目链接：[https://leetcode-cn.com/problems/jump-game](https://leetcode-cn.com/problems/jump-game)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0055.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0055.cpp)  
运行时间：beats 88.33%  
解题思路：初始变量pathLength = nums[0]，记录可以到达最大的下标，在遍历nums过程中，如果i > pathLength，则表示i点已经不可到达，返回false，如果pathLength >= 数组最大下标，则表示数组最后一点可到达，返回true
#### <span id=0056>[56] 合并区间</span>
题目链接：[https://leetcode-cn.com/problems/merge-intervals](https://leetcode-cn.com/problems/merge-intervals)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0056.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0056.cpp)  
运行时间：beats 93.82%  
解题思路：为了使两个不重叠区间因为合并了另外一个区间而变得重叠，可以先对intervals进行排序，使得区间左端点从小到大排列，然后遍历intervals数组，合并重复区间并加入到返回列表中
#### <span id=0057>[57] 插入区间</span>
题目链接：[https://leetcode-cn.com/problems/insert-interval](https://leetcode-cn.com/problems/insert-interval)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0057.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0057.cpp)  
运行时间：beats 51.65%  
解题思路：通过newInterval找到在intervals重叠的左区间下标beginIdx，因为intervals已经顺序排列，所以从beginIdx开始找到重叠的右区间下标endIdx，在intervals上合并这些区间，并将endIdx后面的元素往前移动，对intervals进行resize之后返回intervals；需要注意一些特殊情况，比如找不到beginIdx，endIdx，或endIdx小于beginIdx等
#### <span id=0058>[58] 最后一个单词的长度</span>
题目链接：[https://leetcode-cn.com/problems/length-of-last-word](https://leetcode-cn.com/problems/length-of-last-word)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0058.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0058.cpp)  
运行时间：beats 100%  
解题思路：从后往前遍历，过滤掉空格之后开始计数，直至遇到空格结束
#### <span id=0059>[59] 螺旋矩阵-ii</span>
题目链接：[https://leetcode-cn.com/problems/spiral-matrix-ii](https://leetcode-cn.com/problems/spiral-matrix-ii)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0059.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0059.cpp)  
运行时间：beats 100%  
解题思路：[54 螺旋矩阵](#0054)的反操作，54题为了提高cpu cache命中率，采用了顺序遍历矩阵的方式，将坐标对进行了转换，这题同理，为了提高cpu的回写效率，同样以顺序方式进行遍历，将坐标对转换成第几个数即可
#### <span id=0060>[60] 排列序列</span>
题目链接：[https://leetcode-cn.com/problems/permutation-sequence](https://leetcode-cn.com/problems/permutation-sequence)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0060.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0060.cpp)  
运行时间：beats 100%  
解题思路：从后往前计算排列数，比如n = 7，k = 9，计算到倒数第4位的时候发现4! == 24 >= 9，说明第9个排列必然是从倒数第4位开始变化出来的，而第1位到第3位保持原有序列"123"；从倒数第四位开始往后遍历，获取当前位置剩余的最小数num，当k大于下一个位置的最大排列数A时，表明当前位置为num时的总排列数小于k，此时将k - A，继续在当前位置获取下一个剩余最小数  
时间复杂度为O(N)，浏览评论的时候发现[康托展开](https://baike.baidu.com/item/%E5%BA%B7%E6%89%98%E5%B1%95%E5%BC%80/7968428?fr=aladdin)能更加专业的解决这个问题
#### <span id=0061>[61] 旋转链表</span>
题目链接：[https://leetcode-cn.com/problems/rotate-list](https://leetcode-cn.com/problems/rotate-list)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0061.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0061.cpp)  
运行时间：beats 55.64%  
解题思路：由于旋转链表需要知道链表长度，所以需要提前遍历一次链表，为了不重复遍历，在事先遍历的同时用vector保存每一位置的结点，将k对length取余后，得到新的尾结点索引为length - 1 - k，将原头尾结点相连和将新尾结点置null后，返回新的头结点，位于索引length - k。事实证明，还不如多遍历一次链表，vector的申请空间和赋值操作同样耗时
#### <span id=0062>[62] 不同路径</span>
题目链接：[https://leetcode-cn.com/problems/unique-paths](https://leetcode-cn.com/problems/unique-paths)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0062.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0062.cpp)  
运行时间：beats 100%  
解题思路：高中的排列组合题，求某两个对角点最短路径的数目，比如m行n列的网格，从左上角的点到右下角的点，那么最短路径就只能往下或往右走，即往右走n次，往下走m次，不同的路径就是往下或往右走的时机不同，故路经数为$C_{n+m}^m$或$C_{n+m}^n$  
也可以采用动态规划求解，到达某点的最短路径数等于相邻两点（最短路径上）的最短路径数目之和，所以可以从起点开始，一步步往下求解  
题目是基于格子而不是点，但解法一致，m行n列的网格可以看作m-1行n-1列的格子组合，也可以看作，向右或向下少走一步，即$C_{n+m-2}^{m-1}$或$C_{n+m-2}^{n-1}$  
#### <span id=0063>[63] 不同路径-ii</span>
题目链接：[https://leetcode-cn.com/problems/unique-paths-ii](https://leetcode-cn.com/problems/unique-paths-ii)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0063.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0063.cpp)  
运行时间：beats 56.13%  
解题思路：类似[62 不同路径](#0062)，由于在网格中加入了障碍物，所以上述两种方法中只能选择dp求解
#### <span id=0064>[64] 最小路径和</span>
题目链接：[https://leetcode-cn.com/problems/minimum-path-sum](https://leetcode-cn.com/problems/minimum-path-sum)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0064.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0064.cpp)  
运行时间：beats 76.92%  
解题思路：类似[63 不同路径-ii](#0063)，只是记录路径数变成记录了最小路径和
#### <span id=0065>[65] 有效数字</span>
题目链接：[https://leetcode-cn.com/problems/valid-number](https://leetcode-cn.com/problems/valid-number)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0065.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0065.cpp)  
运行时间：beats 58.06%  
解题思路：有效数字的状态不多，可以很容易的通过分支判断进行解答，但是相比之下，有限状态自动机的做法才是正途，将每一个状态都作为状态转换的枢纽，简化转换策略，思路更加清晰简洁  
参考：[确定有限状态自动机](https://leetcode.cn/problems/valid-number/solution/you-xiao-shu-zi-by-leetcode-solution-298l/) [有限状态自动机](https://zhuanlan.zhihu.com/p/400108593) [有限自动机](https://baike.baidu.com/item/%E6%9C%89%E9%99%90%E8%87%AA%E5%8A%A8%E6%9C%BA/8700995?fr=aladdin)
#### <span id=0066>[66] 加一</span>
题目链接：[https://leetcode-cn.com/problems/plus-one](https://leetcode-cn.com/problems/plus-one)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0066.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0066.cpp)  
运行时间：beats 100%  
解题思路：设置溢出位从后往前加，如果溢出位为0，提前结束返回，如果遍历结束后仍没有返回，则说明此时溢出位为1，往数组头部插入1返回即可
#### <span id=0067>[67] 二进制求和</span>
题目链接：[https://leetcode-cn.com/problems/add-binary](https://leetcode-cn.com/problems/add-binary)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0067.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0067.cpp)  
运行时间：beats 100%  
解题思路：设置溢出位从后往前加，先加两个字符串处于同一加法位置的部分，再单独加最长字符串的剩余部分，如果到最后仍然有溢出位，则向返回字符串头部插入'1'
#### <span id=0068>[68] 文本左右对齐</span>
题目链接：[https://leetcode-cn.com/problems/text-justification](https://leetcode-cn.com/problems/text-justification)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0068.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0068.cpp)  
运行时间：beats 100%  
解题思路：有点奇怪的题目，没有get到考察点。具体做法很简单，首先尽可能多的放置单词，即每个单词之间只留一个空格，长度超出maxWidth时结束放置，期间记录所有单词总长度length，这时候通过(maxWidth - length) / 空格集合数，计算出当前空格集合应该放置多少个空格c，因为左边空格必须多于右边空格，当c * 空格集合数 != maxWidth - length时，c自增1；循环计算，直至插完当前的所有单词；当插入的是最后一行时，特殊处理一下，即每个单词间空格数恒定为1
