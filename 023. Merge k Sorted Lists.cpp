//23. Merge k Sorted Lists
//复用mergeTwoSortedLists
//可优化，从最短的两个list开始合并

#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *p = nullptr;
		for (auto list : lists) {
			p = mergeTwoLists(p, list);
		}
		return p;
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		ListNode *head = new ListNode(0);
		ListNode *curr = head;
		while (l1&&l2) {
			if (l1->val <= l2->val) {
				curr->next = l1;
				l1 = l1->next;
			}
			else {
				curr->next = l2;
				l2 = l2->next;
			}
			curr = curr->next;
		}
		curr->next = l1 ? l1 : l2;
		return head->next;
	}
};