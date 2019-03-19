//143. Reorder List
//Medium

/*
S1: ²ð±í
S2: ÄæÐò
S3: ºÏ²¢
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return;
		ListNode *slow = head, *fast = head->next;
		while (fast != nullptr&&fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *curr = slow->next, *prev = nullptr;
		slow->next = nullptr;
		while (curr != nullptr) {
			ListNode* tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
		ListNode *p = head, *q = prev;
		while (q != nullptr) {
			ListNode *tmp1 = p->next, *tmp2 = q->next;
			p->next = q;
			q->next = tmp1;
			p = tmp1;
			q = tmp2;
		}
	}
};