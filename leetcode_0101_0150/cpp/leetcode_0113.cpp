/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
using namespace std;
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> set;
        vector<TreeNode*> st;
        TreeNode* tr = nullptr;
        int curSum = 0;
        while(root || !st.empty()){
            if(root){
                st.emplace_back(root);
                curSum += root->val;
                if(curSum == targetSum && !root->left && !root->right){
                    set.emplace_back();
                    for(size_t i = 0; i < st.size(); i++)
                        set.back().emplace_back(st[i]->val);
                }
                root = root->left;
            }
            else{
                if(!st.back()->right || st.back()->right == tr){
                    tr = st.back();
                    curSum -= tr->val;
                    st.resize(st.size() - 1);
                }
                else
                    root = st.back()->right;
            }
        }
        return set;
    }
};
// @lc code=end

