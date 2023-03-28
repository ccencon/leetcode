/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>
using namespace std;
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        unordered_map<Node*, Node*> pointers; Node* n = head;
        for(int i = 0; n; i++, n = n->next){
            if(pointers.find(n) == pointers.end())
                pointers[n] = new Node(n->val);
            if(n->next){
                if(pointers.find(n->next) == pointers.end())
                    pointers[n->next] = new Node(n->next->val);
                pointers[n]->next = pointers[n->next];
            }
            if(n->random){
                if(pointers.find(n->random) == pointers.end())
                    pointers[n->random] = new Node(n->random->val);
                pointers[n]->random = pointers[n->random];
            }
        }
        return pointers[head];
    }
};
// @lc code=end

