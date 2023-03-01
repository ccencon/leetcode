/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
#include <queue>
using namespace std;
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> que;
        que.emplace(p, q);
        while(!que.empty()){
            pair<TreeNode*, TreeNode*> tt = que.front(); que.pop();
            if(!tt.first || !tt.second){
                if(tt.first != tt.second)
                    return false;
            }
            else{
                if(tt.first->val != tt.second->val)
                    return false;
                que.emplace(tt.first->left, tt.second->left);
                que.emplace(tt.first->right, tt.second->right);
            }
        }
        return true;
    }
};
// @lc code=end

