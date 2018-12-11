// 2. Add Two Numbers

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) {
		val = x;
		next = NULL;
	}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* ret = new ListNode(0);
		ListNode* r = ret;
		int flag = 0;
		while (p != NULL || q != NULL || flag > 0) {
			int pv = p ? p->val : 0;
			int qv = q ? q->val : 0;
			r->next = new ListNode(pv + qv + flag);
			r = r->next;
			flag = r->val / 10;
			r->val = r->val % 10;
			p = p ? p->next : NULL;
			q = q ? q->next : NULL;
		}
		r->next = NULL;
		return ret->next;
	}
};
