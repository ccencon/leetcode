/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nth = 0;
        ListNode* nthNode = head;
        for(ListNode* node = head; node != nullptr; node = node->next){
            if(nth >= n + 1)
                nthNode = nthNode->next;
            else
                nth++;
        }
        if(nth == n + 1)
            nthNode->next = nthNode->next->next;
        else if(nth == n)
            head = head->next;
        return head;
    }
};
// @lc code=end

