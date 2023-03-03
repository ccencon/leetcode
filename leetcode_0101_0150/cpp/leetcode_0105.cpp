/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
#include <functional>
using namespace std;
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        function<TreeNode*(int, int, int)> dfs = [&](int ip, int ii, int length){
            TreeNode* root = nullptr;
            if(length > 0){
                root = new TreeNode(preorder[ip]);
                int l = 0;
                while(inorder[ii + l] != preorder[ip]) l++;
                root->left = dfs(ip + 1, ii, l);
                root->right = dfs(ip + 1 + l, ii + 1 + l, length - l - 1);
            }
            return root;
        };
        return dfs(0, 0, preorder.size());
    }
};
// @lc code=end

