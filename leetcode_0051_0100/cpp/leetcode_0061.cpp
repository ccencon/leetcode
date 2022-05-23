/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
            return head;
        ListNode* tail = head;
        vector<ListNode*> list = {tail};
        while(tail->next){
            tail = tail->next;
            list.push_back(tail);
        }
        k %= list.size();
        if(k == 0)
            return head;
        tail->next = head;
        list[list.size() - 1 - k]->next = nullptr;
        return list[list.size() - k];
    }
};
// @lc code=end

