/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode* n = head;
        while(true){
            if(!n->next)
                return false;
            if(n->next == head)
                return true;
            ListNode* _n = n->next;
            n->next = head;
            n = _n;
        }
    }
};
// @lc code=end

