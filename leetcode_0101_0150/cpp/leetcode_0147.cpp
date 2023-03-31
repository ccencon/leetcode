/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        for(ListNode* prev = head, *n = prev->next; n; n = prev->next){
            if(n->val >= prev->val){
                prev = n;
                continue;
            }
            ListNode* n1 = nullptr, *n2 = head;
            while(n->val > n2->val){
                n1 = n2;
                n2 = n2->next;
            }
            prev->next = n->next;
            if(n1){
                n1->next = n;
                n->next = n2;
            }
            else{
                n->next = n2;
                head = n;
            }
        }
        return head;
    }
};
// @lc code=end

