/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        function<TreeNode*(int, int, int)> dfs = [&](int ii, int ip, int l){
            TreeNode* node = nullptr;
            if(l > 0){
                node = new TreeNode(postorder[ip + l - 1]);
                int _l = 0;
                while(inorder[ii + _l] != postorder[ip + l - 1]) _l++;
                node->left = dfs(ii, ip, _l);
                node->right = dfs(ii + _l + 1, ip + _l, l - _l - 1);
            }
            return node;
        };
        return dfs(0, 0, inorder.size());
    }
};
// @lc code=end

