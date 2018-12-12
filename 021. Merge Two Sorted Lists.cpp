//21. Merge Two Sorted Lists
//Easy


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
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		ListNode headNode(-1);
		ListNode *p = &headNode;
		while (l1&&l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		p->next = l1 != nullptr ? l1 : l2;		//若都为0，末尾指向nullptr
		return headNode.next;
	}
};