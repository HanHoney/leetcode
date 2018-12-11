//24. Swap Nodes in Pairs

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
class Solution {
public:
	ListNode * swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode l = ListNode(0);
		ListNode *p, *q;
		l.next = head;
		head = &l;
		p = head;
		q = p->next;
		while (q&&q->next) {
			ListNode *t = q->next;
			q->next = t->next;
			t->next = q;
			p->next = t;
			p = q;
			q = p->next;
		}
		return head->next;
	}

	ListNode* swapPairs2(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode headNode = ListNode(0);
		headNode.next = head;
		head = &headNode;
		ListNode *p = head->next;
		while (p&&p->next) {
			int data = p->val;
			p->val = p->next->val;
			p->next->val = data;
			p = p->next->next;
		}
		return head->next;
	}
};