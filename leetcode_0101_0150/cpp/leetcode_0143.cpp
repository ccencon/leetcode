/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
#include <vector>
using namespace std;
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> list;
        for(ListNode* n = head; n; n = n->next)
            list.emplace_back(n);
        for(int i = 0; i < list.size() / 2; i++){
            list[i]->next = list[list.size() - 1 - i];
            list[list.size() - 1 - i]->next = list[i + 1];
        }
        list[list.size() / 2]->next = nullptr;
    }
};
// @lc code=end

