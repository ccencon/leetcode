/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int, int)> dfs = [&](int ib, int ie){
            TreeNode* node = nullptr;
            if(ie == ib)
                node = new TreeNode(nums[ie]);
            if(ie > ib){
                int m = (ib + ie) / 2;
                node = new TreeNode(nums[m]);
                node->left = dfs(ib, m - 1);
                node->right = dfs(m + 1, ie);
            }
            return node;
        };
        return dfs(0, nums.size() - 1);
    }
};
// @lc code=end

