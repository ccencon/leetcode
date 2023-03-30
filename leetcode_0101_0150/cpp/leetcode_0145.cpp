/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* bt = nullptr;
        while(root || !st.empty()){
            if(root){
                st.emplace(root);
                root = root->left;
            }
            else{
                if(!st.top()->right || st.top()->right == bt){
                    ans.emplace_back(st.top()->val);
                    bt = st.top(); st.pop();
                }
                else
                    root = st.top()->right;
            }
        }
        return ans;
    }
};
// @lc code=end

