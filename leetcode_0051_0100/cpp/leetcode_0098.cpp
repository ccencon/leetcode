/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include <climits>
using namespace std;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        long long pivot = LLONG_MIN;
        while(root || !st.empty()){
            if(root){
                st.emplace(root);
                root = root->left;
            }
            else{
                root = st.top(); st.pop();
                if(root->val <= pivot)
                    return false;
                pivot = root->val;
                root = root->right;
            }
        }
        return true;
    }
};
// @lc code=end

