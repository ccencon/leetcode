/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start

//Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* next = head->next;
        ListNode* nn = next->next;
        ListNode* prior = head;
        head->next = nn;
        next->next = head;
        head = next;
        while(nn && nn->next){
            ListNode* tmp = nn->next->next;
            nn->next->next = nn;
            prior->next = nn->next;
            nn->next = tmp;
            prior = nn;
            nn = tmp;
        }
        return head;
    }
};
// @lc code=end

