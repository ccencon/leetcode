/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
#include <list>
using namespace std;
//1-
// class Solution {
// public:
//     TreeNode* sortedListToBST(ListNode* head) {
//         list<pair<TreeNode*, int>> route;
//         while(head){
//             TreeNode* root = new TreeNode(head->val);
//             if(!route.empty())
//                 route.front().first->right = root;
//             route.emplace_front(root, 0);
//             int rh = 0;
//             for(list<pair<TreeNode*, int>>::iterator it = route.begin(); it != route.end(); it++, rh++){
//                 if(rh - it->second > 1){
//                     TreeNode* cur = it->first;
//                     TreeNode* rc = cur->right;
//                     cur->right = rc ->left;
//                     rc ->left = cur;
//                     prev(it)->second++;
//                     if(next(it) != route.end())
//                         next(it)->first->right = rc;
//                     route.erase(it);
//                     break;
//                 }
//             }
//             head = head->next;
//         }
//         return route.empty() ? nullptr : route.back().first;
//     }
// };
//2-
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        list<TreeNode*> route;
        int count = 1;
        while(head){
            TreeNode* root = new TreeNode(head->val);
            if(!route.empty())
                route.back()->right = root;
            route.emplace_back(root);
            if((count & (count - 1)) != 0){
                list<TreeNode*>::iterator it = prev(prev(prev(route.end())));
                int _c = count;
                while((_c & 0x1) == 0){
                    _c >>= 1;
                    it--;
                }
                TreeNode* cur = *it, *rc = cur->right;
                cur->right = rc ->left;
                rc ->left = cur;
                if(it != route.begin())
                    (*prev(it))->right = rc;
                route.erase(it);
            }
            head = head->next;
            count++;
        }
        return route.empty() ? nullptr : route.front();
    }
};
// @lc code=end

