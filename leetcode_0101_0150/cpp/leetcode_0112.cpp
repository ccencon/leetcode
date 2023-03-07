/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        stack<TreeNode*> st;
        int curSum = 0;
        TreeNode* tr = nullptr;
        while(root || !st.empty()){
            if(root){
                st.emplace(root);
                curSum += root->val;
                if(curSum == targetSum && !root->left && !root->right)
                    return true;
                root = root->left;
            }
            else{
                if(!st.top()->right || st.top()->right == tr){
                    tr = st.top();
                    st.pop();
                    curSum -= tr->val;
                }
                else
                    root = st.top()->right;
            }
        }
        return false;
    }
};
// @lc code=end

