//147. Insertion Sort List
//Medium

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *p = head->next;
		head->next = nullptr;
		while (p != nullptr) {
			ListNode *curr = head, *prev = nullptr;
			while (curr != nullptr) {
				if (p->val>curr->val) {
					prev = curr;
					curr = curr->next;
				}
				else break;
			}
			ListNode *tmp = p->next;
			if (prev != nullptr) prev->next = p;
			else head = p;
			p->next = curr;
			p = tmp;
		}
		return head;
	}
};