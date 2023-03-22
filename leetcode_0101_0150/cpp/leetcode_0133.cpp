/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <functional>
using namespace std;
//1-dfs
// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if(!node)
//             return nullptr;
//         Node* pointers[101];
//         ::memset(pointers, 0, sizeof(pointers));
//         function<void(Node*)> helper = [&](Node* n){
//             pointers[n->val] = new Node(n->val);
//             for(auto v : n->neighbors){
//                 if(!pointers[v->val])
//                     helper(v);
//                 pointers[n->val]->neighbors.emplace_back(pointers[v->val]);
//             }
//         };
//         helper(node);
//         return pointers[node->val];
//     }
// };
//2-bfs
// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if(!node)
//             return nullptr;
//         Node* pointers[101];
//         ::memset(pointers, 0, sizeof(pointers));
//         pointers[node->val] = new Node(node->val);
//         queue<Node*> que; que.emplace(node);
//         while(!que.empty()){
//             Node* n = que.front(); que.pop();
//             for(auto v : n->neighbors){
//                 if(!pointers[v->val]){
//                     pointers[v->val] = new Node(v->val);
//                     que.emplace(v);
//                 }
//                 pointers[n->val]->neighbors.emplace_back(pointers[v->val]);
//             }
//         }
//         return pointers[node->val];
//     }
// };
//3-bfs+dfs
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        Node* pointers[101];
        ::memset(pointers, 0, sizeof(pointers));
        pointers[node->val] = new Node(node->val);
        stack<Node*> que; que.emplace(node);
        while(!que.empty()){
            Node* n = que.top(); que.pop();
            for(auto v : n->neighbors){
                if(!pointers[v->val]){
                    pointers[v->val] = new Node(v->val);
                    que.emplace(v);
                }
                pointers[n->val]->neighbors.emplace_back(pointers[v->val]);
            }
        }
        return pointers[node->val];
    }
};
// @lc code=end

