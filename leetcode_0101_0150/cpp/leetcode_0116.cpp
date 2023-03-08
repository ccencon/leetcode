/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
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
#include <queue>
using namespace std;
class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> que; que.emplace(root);
        while(!que.empty()){
            Node* node = que.front(); que.pop();
            if(!node)
                break;
            int size = que.size();
            que.emplace(node->left);
            que.emplace(node->right);
            for(int i = 0; i < size; i++){
                node->next = que.front();
                node = que.front(); que.pop();
                que.emplace(node->left);
                que.emplace(node->right);
            }
        }
        return root;
    }
};
// @lc code=end

