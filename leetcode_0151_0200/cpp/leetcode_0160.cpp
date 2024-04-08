/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* tailA = headA, *tailB = headB;
        while(tailA){
            tailA = tailA->next;
            lenA++;
        }
        while(tailB){
            tailB = tailB->next;
            lenB++;
        }
        if(lenA == 0 || lenB == 0 || tailA != tailB)
            return nullptr;
        tailA = headA; tailB = headB;
        if(lenA > lenB)
            for(int i = 0; i < lenA - lenB; i++)
                tailA = tailA->next;
        else if(lenA < lenB)
            for(int i = 0; i < lenB - lenA; i++)
                tailB = tailB->next;
        while(true){
            if(tailA == tailB)
                return tailA;
            tailA = tailA->next;
            tailB = tailB->next;
        }
    }
};
// @lc code=end

