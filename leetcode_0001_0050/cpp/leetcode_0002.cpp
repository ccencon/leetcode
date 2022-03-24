/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start

/*
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flow = 0;
        ListNode* _head = nullptr, *_end = nullptr;
        while(l1 || l2 || flow){
            if (l1){
                flow += l1->val;
                l1 = l1->next;
            }
            if (l2){
                flow += l2->val;
                l2 = l2->next;
            }
            ListNode* node = new ListNode(flow % 10);
            if (!_head)
                _head = _end = node;
            else{
                _end->next = node;
                _end = node;
            }
            flow /= 10;
        }
        return _head;
    }
};
// @lc code=end

