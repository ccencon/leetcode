/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        ListNode newHead(0, head);
        ListNode* pb = head, *pe = head, *prior = &newHead;
        while(pb){
            int count = 0;
            while(++count != k && pe)
                pe = pe->next;
            if(!pe)
                break;
            ListNode* np = pe->next;
            prior->next = pe;
            prior = pb;
            do{
                ListNode* pbNext = pb->next;
                pb->next = pe->next;
                pe->next = pb;
                pb = pbNext;
            }while(pb != pe);
            pb = pe = np;
        }
        return newHead.next;
    }
};
// @lc code=end

