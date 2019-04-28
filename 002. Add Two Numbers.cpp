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
		ListNode *p = l1;
		ListNode *q = l2;
		ListNode *head = new ListNode(0);
		ListNode *curr = head;
		int carry = 0;
		while (p != nullptr || q != nullptr || carry > 0) {
			int x = p ? p->val : 0;
			int y = q ? q->val : 0;
			int sum = x + y + carry;
			curr->next = new ListNode(sum % 10);
			carry = sum / 10;
			curr = curr->next;
			p = p ? p->next : nullptr;
			q = q ? q->next : nullptr;
		}
		return head->next;
	}
};
