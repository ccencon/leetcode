/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        stack<TreeNode*> que1, que2; que1.emplace(root);
        stack<TreeNode*> *pq = &que1, *qpe = &que2;
        vector<vector<int>> set;
        do{
            set.emplace_back();
            while(!pq->empty()){
                TreeNode* n = pq->top(); pq->pop();
                set.back().emplace_back(n->val);
                if(pq == &que1){
                    if(n->left)
                        qpe->emplace(n->left);
                    if(n->right)
                        qpe->emplace(n->right);
                }
                else{
                    if(n->right)
                        qpe->emplace(n->right);
                    if(n->left)
                        qpe->emplace(n->left);
                }
            }
            swap(pq, qpe);
        }while(!pq->empty());
        return set;
    }
};
// @lc code=end

