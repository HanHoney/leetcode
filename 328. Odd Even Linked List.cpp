//328. Odd Even Linked List
//Medium
//按结点序号的奇偶重排链表

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode * oddEvenList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* p = head;
		ListNode* head2 = head->next;
		ListNode* q = head2;
		while (p != nullptr && p->next != nullptr) {
			p->next = q->next;
			if (p->next != nullptr) {
				q->next = p->next->next;
			}
			if (p->next != nullptr) {
				p = p->next;
			}
			if (q->next != nullptr) {
				q = q->next;
			}
		}
		p->next = head2;
		q->next = nullptr;
		return head;
	}
};
