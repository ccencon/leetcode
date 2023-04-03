/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
//1-merging-sort
class Solution {
    pair<ListNode*, ListNode*> mergeList(ListNode* l1, ListNode* l2){
        ListNode hair(0), *travel = &hair;
        while(l1 && l2){
            if(l1->val >= l2->val){
                travel->next = l2;
                l2 = l2->next;
            }
            else{
                travel->next = l1;
                l1 = l1->next;
            }
            travel = travel->next;
        }
        if(l1)
            travel->next = l1;
        else
            travel->next = l2;
        while(travel->next)
            travel = travel->next;
        return pair<ListNode*, ListNode*>(hair.next, travel);
    }
public:
	ListNode* sortList(ListNode* head) {
        ListNode hair(0); hair.next = head;
        bool finished = false;
        for(int len = 1; !finished; len <<= 1){
            ListNode* travel = hair.next, *prev = &hair;
            int times = 0;
            while(++times){
                ListNode* h1 = travel;
                for(int l = 1; l < len && travel; l++, travel = travel->next){}
                if(!travel || !travel->next){
                    finished = times == 1 ? true : finished;
                    break;
                }
                ListNode* h2 = travel->next;
                travel->next = nullptr;
                travel = h2;
                for(int l = 1; l < len && travel; l++, travel = travel->next){}
                if(travel){
                    ListNode* tmp = travel->next;
                    travel->next = nullptr;
                    travel = tmp;
                }
                pair<ListNode*, ListNode*> ret = mergeList(h1, h2);
                prev->next = ret.first;
                ret.second->next = travel;
                prev = ret.second;
                if(!travel){
                    finished = times == 1 ? true : finished;
                    break;
                }
            }
        }
        return hair.next;
    }
};
//2-quick-sort，过不了后面几个测试用例（超时）
// class Solution {
// public:
// 	ListNode* sortList(ListNode* head) {
// 		function<pair<ListNode*, ListNode*>(ListNode*)> helper = [&](ListNode* n){
// 			if (!n)
// 				return make_pair(n, n);
// 			ListNode* _h = n, *_t = n, *left = nullptr, *right = nullptr;
// 			n = n->next; _t->next = nullptr;
// 			while (n){
// 				ListNode* nn = n->next;
// 				if (n->val == _h->val){
// 					n->next = _h;
// 					_h = n;
// 				}
// 				else if (n->val < _h->val){
// 					n->next = left;
// 					left = n;
// 				}
// 				else{
// 					n->next = right;
// 					right = n;
// 				}
// 				n = nn;
// 			}
// 			pair<ListNode*, ListNode*> p1 = helper(left);
// 			pair<ListNode*, ListNode*> p2 = helper(right);
// 			if (p1.second){
// 				p1.second->next = _h;
// 				_h = p1.first;
// 			}
// 			if (p2.first){
// 				_t->next = p2.first;
// 				_t = p2.second;
// 			}
// 			return make_pair(_h, _t);
// 		};
// 		return helper(head).first;
// 	}
// };
// @lc code=end

