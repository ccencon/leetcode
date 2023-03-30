/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(true){
            if(!fast || !fast->next)
                return nullptr;
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        while(head != slow){
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};
// @lc code=end

