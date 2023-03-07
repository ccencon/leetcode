/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
#include <queue>
using namespace std;
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int depth = 0;
        queue<TreeNode*> que; que.emplace(root);
        while(true){
            depth++;
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front(); que.pop();
                if(!node->left && !node->right)
                    return depth;
                if(node->left)
                    que.emplace(node->left);
                if(node->right)
                    que.emplace(node->right);
            }
        }
    }
};
// @lc code=end

