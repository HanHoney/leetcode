//23. Merge k Sorted Lists
//复用mergeTwoSortedLists
//可优化，从最短的两个list开始合并

#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) return NULL;
		ListNode* p = lists[0];
		for (int i = 1; i < lists.size(); i++) {
			p = mergeTwoLists(p, lists[i]);
		}
		return p;
	}
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode headNode = ListNode(-1);
		ListNode *cur = &headNode;
		ListNode *p1 = l1, *p2 = l2;
		while (p1&&p2) {
			if (p1->val < p2->val) {
				cur->next = p1;
				cur = cur->next;
				p1 = p1->next;
			}
			else {
				cur->next = p2;
				cur = cur->next;
				p2 = p2->next;
			}
		}
		if (p1) {
			cur->next = p1;
		}
		if (p2) { 
			cur->next = p2; 
		}
		return headNode.next;
	}
};