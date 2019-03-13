// 2. Add Two Numbers
// Medium

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) {
		val = x;
		next = nullptr;
	}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* dummyHead = new ListNode(0);
		ListNode* curr = dummyHead;
		int carry = 0;
		while (p != nullptr || q != nullptr || carry > 0) {
			int pv = p ? p->val : 0;
			int qv = q ? q->val : 0;
			curr->next = new ListNode(pv + qv + carry);
			curr = curr->next;
			carry = curr->val / 10;
			curr->val = curr->val % 10;
			p = p ? p->next : nullptr;
			q = q ? q->next : nullptr;
		}
		curr->next = nullptr;
		return dummyHead->next;
	}
};
