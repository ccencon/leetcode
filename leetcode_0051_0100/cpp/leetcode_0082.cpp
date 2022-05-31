/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode hair(0, head);
        ListNode* slow = &hair, *fast = head;
        while(fast){
            ListNode* pivot = fast;
            while(fast->next && fast->next->val == pivot->val)
                fast = fast->next;
            if(fast == pivot){
                slow->next = fast;
                slow = fast;
            }
            fast = fast->next;
        }
        slow->next = nullptr;
        return hair.next;
    }
};
// @lc code=end

