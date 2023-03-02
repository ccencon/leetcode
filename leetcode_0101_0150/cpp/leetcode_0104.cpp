/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* tr = nullptr;
        int maxDepth = 0, curDepth = 0;
        while(root || !st.empty()){
            if(root){
                st.emplace(root);
                root = root->left;
                maxDepth = max(maxDepth, ++curDepth);
            }
            else{
                if(!st.top()->right || st.top()->right == tr){
                    tr = st.top(); st.pop();
                    --curDepth;
                }
                else
                    root = st.top()->right;
            }
        }
        return maxDepth;
    }
};
// @lc code=end

