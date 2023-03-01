/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
#include <functional>
#include <algorithm>
using namespace std;
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        vector<TreeNode*> nodes;
        TreeNode* pivot = nullptr;
        while(root || !st.empty()){
            if(root){
                st.emplace(root);
                root = root->left;
            }
            else{
                root = st.top(); st.pop();
                if(pivot && root->val < pivot->val){
                    if(nodes.empty()){
                        nodes.emplace_back(pivot);
                        nodes.emplace_back(root);
                    }
                    else{
                        if(pivot != nodes[1])
                            nodes.emplace_back(pivot);
                        nodes.emplace_back(root);
                        break;
                    }
                }
                pivot = root;
                root = root->right;
            }
        }
        function<bool(TreeNode*, TreeNode*)> cmp = [](TreeNode* lhs, TreeNode* rhs){
            return rhs->val > lhs->val;
        };
        vector<TreeNode*> cpy(nodes);
        sort(cpy.begin(), cpy.end(), cmp);
        for(size_t i = 0; i < cpy.size(); i++){
            if(nodes[i] != cpy[i]){
                swap(nodes[i]->val, cpy[i]->val);
                break;
            }
        }
    }
};
// @lc code=end

