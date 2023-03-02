# leetcode_0101_0150
|order|question|cpp link|
|:-|:-|:-|
|[0101](#0101)|[对称二叉树](#0101)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0101.cpp)|
|[0102](#0102)|[二叉树的层序遍历](#0102)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0102.cpp)|
|[0103](#0103)|[二叉树的锯齿形层序遍历](#0103)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0103.cpp)|
|[0104](#0104)|[二叉树的最大深度](#0104)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0104.cpp)|

#### <span id=0101>[101] 对称二叉树</span>
题目链接：[https://leetcode-cn.com/problems/symmetric-tree](https://leetcode-cn.com/problems/symmetric-tree)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0101.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0101.cpp)  
运行时间：beats 76%  
解题思路：因为树是对称的数据结构，所以基于树的算法也必然能以对称方式实现；采用层级遍历root结点的左右子树，将左子树的左右结点与右子树的右左结点进行迭代比较即可
#### <span id=0102>[102] 二叉树的层序遍历</span>
题目链接：[https://leetcode-cn.com/problems/binary-tree-level-order-traversal](https://leetcode-cn.com/problems/binary-tree-level-order-traversal)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0102.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0102.cpp)  
运行时间：beats 100%  
解题思路：层序遍历的基本算法，额外的点在于如何确定每层个数；这里采用两个队列实现，下一层的结点将加入到另外一个队列，交替读取两个队列
#### <span id=0103>[103] 二叉树的锯齿形层序遍历</span>
题目链接：[https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal](https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0103.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0103.cpp)  
运行时间：beats 60.53%  
解题思路：与[[102] 二叉树的层序遍历](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150#0102)类似，这里不再叙述
#### <span id=0104>[104] 二叉树的最大深度</span>
题目链接：[https://leetcode-cn.com/problems/maximum-depth-of-binary-tree](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0104.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0104.cpp)  
运行时间：beats 100%  
解题思路：从根结点开始递归左右子树，取最大值加一；或者采用层级遍历的方式。还记得以前实现过栈形式的后序遍历，一个结点只有在左右子树迭代完之后才会出栈，所以栈实现的后序遍历也同样可以应用于计算树的最大深度，这里采用的也是此方法；值得注意的是，后序遍历的栈实现，需要一个额外结点用来记录上一次出栈结点，当再次取栈顶元素时，判断其右孩子是否与之相等来决定是否出栈
