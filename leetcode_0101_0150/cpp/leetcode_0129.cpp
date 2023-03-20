/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
#include <functional>
using namespace std;
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        function<void(TreeNode*, int)> helper = [&](TreeNode* node, int factor){
            factor = factor * 10 + node->val;
            if(!node->left && !node->right){
                sum += factor;
                return;
            }
            if(node->left)
                helper(node->left, factor);
            if(node->right)
                helper(node->right, factor);
        };
        helper(root, 0);
        return sum;
    }
};
// @lc code=end

