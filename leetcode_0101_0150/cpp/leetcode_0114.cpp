/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        TreeNode tail;
        TreeNode* pt = &tail;
        stack<TreeNode*> st; st.emplace(root);
        while(!st.empty()){
            root = st.top(); st.pop();
            if(root){
                st.emplace(root->right);
                st.emplace(root->left);
                root->left = nullptr;
                pt->right = root;
                pt = root;
            }
        }
    }
};
// @lc code=end

