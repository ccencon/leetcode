# leetcode_0101_0150
|order|question|cpp link|
|:-|:-|:-|
|[0101](#0101)|[对称二叉树](#0101)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0101.cpp)|

#### <span id=0101>[101] 对称二叉树</span>
题目链接：[https://leetcode-cn.com/problems/symmetric-tree](https://leetcode-cn.com/problems/symmetric-tree)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0101.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0101.cpp)  
运行时间：beats 76%  
解题思路：因为树是对称的数据结构，所以基于树的算法也必然能以对称方式实现；采用层级遍历root结点的左右子树，将左子树的左右结点与右子树的右左结点进行迭代比较即可
