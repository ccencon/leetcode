/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> que1, que2; que1.emplace(root);
        queue<TreeNode*> *pq = &que1, *qpe = &que2;
        vector<vector<int>> set;
        do{
            set.emplace_back();
            while(!pq->empty()){
                TreeNode* n = pq->front(); pq->pop();
                set.back().emplace_back(n->val);
                if(n->left)
                    qpe->emplace(n->left);
                if(n->right)
                    qpe->emplace(n->right);
            }
            swap(pq, qpe);
        }while(!pq->empty());
        return set;
    }
};
// @lc code=end

