/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* b = root;
        while(b){
            Node n;
            Node* pn = &n;
            while(b){
                if(b->left){
                    pn->next = b->left;
                    pn = pn->next;
                }
                if(b->right){
                    pn->next = b->right;
                    pn = pn->next;
                }

                b = b->next;
            }
            b = n.next;
        }
        return root;
    }
};
// @lc code=end

