/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
#include <vector>
using namespace std;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* pivot = nullptr;
        int idx = 0;
        for(; idx < lists.size(); idx++)
            if(lists[idx]){
                pivot = lists[idx];
                break;
            }
        ListNode* rec = pivot;
        for(idx++; idx < lists.size(); idx++){
            auto p = lists[idx];
            while(p){
                ListNode* tmp = p;
                p = p->next;
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
                else{
                    tmp->next = rec;
                    pivot = tmp;
                }
                rec = tmp;
            }
            rec = pivot;
        }
        return pivot;
    }
};
// @lc code=end

