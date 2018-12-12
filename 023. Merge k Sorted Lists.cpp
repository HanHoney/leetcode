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
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) return nullptr;
		ListNode* p = lists[0];
		for (int i = 1; i < lists.size(); i++) {
			p = mergeTwoLists(p, lists[i]);
		}
		return p;
	}
private:
	static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		ListNode headNode = ListNode(-1);
		ListNode *cur = &headNode;
		while (l1&&l2) {
			if (l1->val < l2->val) {
				cur->next = l1;
				cur = cur->next;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				cur = cur->next;
				l2 = l2->next;
			}
		}
		cur->next = l1 != nullptr ? l1 : l2;
		return headNode.next;
	}
};
