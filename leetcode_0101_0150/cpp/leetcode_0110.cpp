/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        function<int(TreeNode*)> helper = [&](TreeNode* root){
            if(!root)
                return 0;
            int lh = helper(root->left);
            if(lh == -1)
                return -1;
            int rh = helper(root->right);
            if(rh == -1)
                return -1;
            if(abs(lh - rh) > 1)
                return -1;
            return max(lh, rh) + 1;
        };
        return helper(root) != -1;
    }
};
// @lc code=end

