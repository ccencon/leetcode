# leetcode_0051_0100
|order|question|cpp link|
|:-|:-|:-|
|[0051](#0051)|[n-皇后](#0051)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0051.cpp)|
|[0052](#0052)|[n皇后-ii](#0052)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0052.cpp)|

#### <span id=0051>[51] n-皇后</span>
题目链接：[https://leetcode-cn.com/problems/n-queens](https://leetcode-cn.com/problems/n-queens)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0051.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0051.cpp)  
运行时间：beats 91.39%  
解题思路：对这类回溯的问题，只要理清如何恢复状态的思路，很容易就可以写出非递归的实现，基本上就是三板斧：  
1. 初始回溯索引traceIdx
2. 从traceIdx开始到结束确定一个新的结果
3. 回溯traceIdx，从后往前恢复状态，当某个位置有未执行的结果时，转到步骤2执行；若回溯了所有位置，结束执行

这种思路的解答基本上运行时间和内存占用都是击败100%，目前在网上还没见到这种思路的出现，这来源于当初写[有向图](https://github.com/ccencon/structdata#DirectedGraph)输出所有拓扑序列和所有关键路径的做法，目前在所有回溯类的题目中，基本上采用了这种解答方式  

这题的具体做法时，设定数组保存每一行，每一列，每一条斜线的匹配状态，初始trace_i，trace_j，从开始到结束确定第一个结果，然后对trace_i，trace_j进行回溯并恢复状态，并从新的trace_i，trace_j开始确定新的结果
#### <span id=0052>[52] n皇后-ii</span>
题目链接：[https://leetcode-cn.com/problems/n-queens-ii](https://leetcode-cn.com/problems/n-queens-ii)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0052.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0051_0100/cpp/leetcode_0052.cpp)  
运行时间：beats 100%  
解题思路：[n-皇后](#0051)一样的做法，只是将返回字符串换成了返回个数，本质上没有变化
