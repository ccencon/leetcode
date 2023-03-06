/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> set;
        queue<TreeNode*> que; que.emplace(root);
        while(!que.empty()){
            int length = que.size();
            set.emplace(set.begin(), vector<int>(length, 0));
            for(int i = 0; i < length; i++){
                TreeNode* node = que.front(); que.pop();
                set[0][i] = node->val;
                if(node->left)
                    que.emplace(node->left);
                if(node->right)
                    que.emplace(node->right);
            }
        }
        return set;
    }
};
// @lc code=end

