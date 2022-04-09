/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        ListNode* rec = list1, *node = list2;
        while(node){//list2向list1合并
            auto tmp = node;
            node = node->next;
            if(rec->val < tmp->val){
                while(rec->next && rec->next->val < tmp->val)
                    rec = rec->next;
                auto tn = rec->next;
                rec->next = tmp;
                tmp->next = tn;
            }
            else if(rec->val == tmp->val){
                auto tn = rec->next;
                rec->next = tmp;
                tmp->next = tn;
            }
            else{//大于只可能发生在合并list2第一个结点的情况下
                tmp->next = rec;
                list1 = tmp;
            }
            rec = tmp;
        }
        return list1;
    }
};
// @lc code=end

