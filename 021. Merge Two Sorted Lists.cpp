//21. Merge Two Sorted Lists

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {};
};

class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode *l2) {
		if (l1 == NULL && l2 == NULL) return NULL;
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode headNode(0);
		ListNode *p1, *p2, *q, *head;
		p1 = l1;
		p2 = l2;
		q = &headNode;
		head = q;
		while (p1&&p2) {
			if (p1->val < p2->val) {
				q->next = p1;
				p1 = p1->next;
			}
			else {
				q->next = p2;
				p2 = p2->next;
			}
			q = q->next;
		}
		if (p1 != NULL) {
			q->next = p1;
		}
		else if (p2 != NULL) {
			q->next = p2;
		}	
		return head->next;
	}
};