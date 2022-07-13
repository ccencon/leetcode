/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
#include <unordered_map>
#include <functional>
using namespace std;
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        unordered_map<unsigned int, vector<TreeNode*>> record;
        function<vector<TreeNode*>(int, int)> dfs = [&](int left, int right){
            if(left > right)
                return vector<TreeNode*>{nullptr};
            auto key = ((unsigned int)left << 16) | right;
            auto it = record.find(key);
            if(it != record.end())//这里复用已使用的树，懒得copy了
                return it->second;
            vector<TreeNode*> trees;
            for(int i = left; i <= right; i++){
                auto leftTrees = dfs(left, i - 1);
                auto rightTrees = dfs(i + 1, right);
                for(auto lt : leftTrees)
                    for(auto rt : rightTrees)
                        trees.emplace_back(new TreeNode(i, lt, rt));
            }
            record[key] = trees;
            return trees;
        };
        return dfs(1, n);
    }
};
// @lc code=end

