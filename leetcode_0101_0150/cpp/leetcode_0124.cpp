/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
#include <climits>
using namespace std;
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        function<int(TreeNode*)> helper = [&](TreeNode* n){
            int leftMax, rootMax = n->val;
            if(n->left){
                leftMax = helper(n->left);
                rootMax = max(rootMax, n->val + leftMax);
            }
            if(n->right){
                int rightMax = helper(n->right);
                rootMax = max(rootMax, n->val + rightMax);
                if(n->left)
                    maxSum = max(maxSum, n->val + leftMax + rightMax);
            }
            maxSum = max(maxSum, rootMax);
            return rootMax;
        };
        helper(root);
        return maxSum;
    }
};
// @lc code=end

