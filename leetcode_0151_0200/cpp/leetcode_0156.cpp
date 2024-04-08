/*
 * @lc app=leetcode.cn id=156 lang=cpp
 *
 * [156] 上下翻转二叉树
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
#include <stack>
using namespace std;
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        stack<TreeNode*> st;
        while(root){
            st.emplace(root);
            root = root->left;
        }
        TreeNode* ret = st.empty() ? nullptr : st.top();
        while(st.size() > 1){
            TreeNode* node = st.top(); st.pop();
            TreeNode* r = st.top();
            node->right = r;
            node->left = r->right;
        }
        if(st.size() == 1){
            st.top()->left = nullptr;
            st.top()->right = nullptr;
        }
        return ret;
    }
};
// @lc code=end

