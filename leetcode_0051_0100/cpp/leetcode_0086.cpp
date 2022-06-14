/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode hair(0, head), *slow = &hair;
        while(slow->next && slow->next->val < x)
            slow = slow->next;
        ListNode* fast = slow->next;
        if(fast){
            while(fast->next){
                if(fast->next->val < x){
                    ListNode* tmp = slow->next;
                    slow->next = fast->next;
                    fast->next = fast->next->next;
                    slow->next->next = tmp;
                    slow = slow->next;
                }
                else
                    fast = fast->next;
            }
        }
        return hair.next;
    }
};
// @lc code=end

