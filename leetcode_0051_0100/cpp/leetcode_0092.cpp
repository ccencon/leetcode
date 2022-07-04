/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode hair(0, head), *pivot = &hair;
        int forward = 0;
        while(++forward != left)
            pivot = pivot->next;
        ListNode* next = pivot->next, *rec = next;
        while(forward++ <= right){
            ListNode* tmp = next;
            next = next->next;
            tmp->next = pivot->next;
            pivot->next = tmp;
        }
        rec->next = next;
        return hair.next;
    }
};
// @lc code=end

