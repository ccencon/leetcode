# leetcode_0101_0150
|order|question|cpp link|
|:-|:-|:-|
|[0101](#0101)|[对称二叉树](#0101)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0101.cpp)|
|[0102](#0102)|[二叉树的层序遍历](#0102)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0102.cpp)|
|[0103](#0103)|[二叉树的锯齿形层序遍历](#0103)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0103.cpp)|
|[0104](#0104)|[二叉树的最大深度](#0104)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0104.cpp)|
|[0105](#0105)|[从前序与中序遍历序列构造二叉树](#0105)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0105.cpp)|
|[0106](#0106)|[从中序与后序遍历序列构造二叉树](#0106)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0106.cpp)|
|[0107](#0107)|[二叉树的层序遍历-ii](#0107)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0107.cpp)|
|[0108](#0108)|[将有序数组转换为二叉搜索树](#0108)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0108.cpp)|
|[0109](#0109)|[有序链表转换二叉搜索树](#0109)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0109.cpp)|
|[0110](#0110)|[平衡二叉树](#0110)|[cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0110.cpp)|

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
#### <span id=0105>[105] 从前序与中序遍历序列构造二叉树</span>
题目链接：[https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0105.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0105.cpp)  
运行时间：beats 37.3%  
解题思路：先序序列的组成，是`根结点+左子树的先序序列+右子树的先序序列`；而中序序列，是`左子树的中序序列+根结点+右子树的中序序列`；所以创建根结点，按照相同的方法递归创建其左右子树，即可构造出完成的二叉树

记得上述方法在数据结构教材中就有，但是一开始并不打算按照这种方式解答；在最初的思路中，是先通过中序序列构建一棵通过右指针连接的单链表树，然后希望通过观察先序序列的规律对其进行左旋从而得出正确的二叉树；因为左旋不改变树的中序，但却可以调整树的先序，潜意识里总觉得这思路可行，但最后要么转化成了递归，要么碰到了死角；由于在这思路上浪费了太多的时间，这里特地记录一下，也不再纠结了
#### <span id=0106>[106] 从中序与后序遍历序列构造二叉树</span>
题目链接：[https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0106.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0106.cpp)  
运行时间：beats 14.81%  
解题思路：与[[105] 从前序与中序遍历序列构造二叉树](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150#0105)一样的思路，其中后序序列的组成，是`左子树的后序序列+右子树的后序序列+根结点`
#### <span id=0107>[107] 二叉树的层序遍历-ii</span>
题目链接：[https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0107.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0107.cpp)  
运行时间：beats 5.12%  
解题思路：题目要求从最底层开始往最上层遍历，这在不知道所有底层结点和父结点的情况下不可能做到，所以只能是按照从顶层往下遍历的方式，最后反转列表。题目提示树的结点数在2000以内，一般情况下树的层数也只是在11层左右，所以解答中采用了头插法；测试用例应该有比较极端的情况，如类似单链表树，使得头插法会导致了过多元素移动，运行时间较长
#### <span id=0108>[108] 将有序数组转换为二叉搜索树</span>
题目链接：[https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0108.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0108.cpp)  
运行时间：beats 94.03%  
解题思路：每次选择数组中间的结点为根结点，左右序列作为左右子树，如此递归下去；因为左右子树结点数之差不会超过1，所以最终得到的树也必然是平衡二叉树
#### <span id=0109>[109] 有序链表转换二叉搜索树</span>
题目链接：[https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0109.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0109.cpp)  
运行时间：beats 88.9%  
解题思路：遍历链表，因为链表已经升序排列，所以只需不断在树的最右边增加新结点，然后进行左旋调整；树的旋转需要计算平衡因子，但一般平衡树的实现会在结点记录高度，如果在这里的实现中用额外空间给每一个结点记录高度，还不如直接将问题转化为[[108] 将有序数组转换为二叉搜索树](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150#0108)更加来得方便。留意到新结点的插入永远是位于树的最右边，那么在插入过程中，只需保存树最右边的路径和路径上结点的左子树高度，在插入后，沿着路径回溯，通过记录的左子树高度计算每一个结点的平衡因子，大于1便进行左旋，由于左旋后的树总体高度不变，所以仅需旋转一次

其实对于不断在树最右边进行插入，树的每一次左旋的时机都可以事先确认；在实现上述思路之前，便打算通过插入的结点数来确定要左旋的位置，不过随着结点数越来越多，计算左旋的位置也越来越复杂；在实现上述思路之后，便通过打印当前结点数来获得旋转位置；可以发现，当结点数为2n+3时（如3、5、7、9...），要左旋的位置为3；当结点数为4n+6时（如6、10、14、18...），要左旋的位置为4；当结点数为8n+12时（如12、20、28、36...），要左旋的位置为5...可以发现，当结点数满足 $(2n+1)*2^k, n>1$ 的时候，要左旋的位置为 $k+3$ ；这种规律可以在平衡二叉树上得到印证：当一棵树进行左旋时，假设往左偏了n个结点，那么这棵树必须补足n个结点才能使它的右子树恢复到这棵树原本的状态；比如一棵只有3个结点，通过右孩子连接的单支树，在往左旋转后，必须再往右补足2个结点才能使它此时的右子树恢复到它原本的状态

由于不可能每一个结点数都映射一个旋转位置，所以在具体实现中，上面两个思路的时间复杂度都为 $O(nlog_2 n)$

题解中有一种分治+中序遍历优化的方法可以达到 $O(n)$ 的时间复杂度，通过链表长度结合中序遍历按照先构建左子树的方式构建整棵树，虽然不喜欢要先遍历一次链表的做法，但这种思路值得记录一下
#### <span id=0110>[110] 平衡二叉树</span>
题目链接：[https://leetcode-cn.com/problems/balanced-binary-tree](https://leetcode-cn.com/problems/balanced-binary-tree)  
代码链接：[https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0110.cpp](https://github.com/ccencon/leetcode/tree/main/leetcode_0101_0150/cpp/leetcode_0110.cpp)  
运行时间：beats 87.96%  
解题思路：递归计算左右子树高度进行判断即可
