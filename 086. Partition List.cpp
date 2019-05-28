//86. Partition List
//Medium

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *dummy1 = new ListNode(0);
		ListNode *dummy2 = new ListNode(0);
		ListNode *curr = head, *p = dummy1, *q = dummy2;
		while (curr != nullptr) {
			if (curr->val < x) {
				p->next = curr;
				p = p->next;
			}
			else {
				q->next = curr;
				q = q->next;
			}
			curr = curr->next;
		}
		q->next = nullptr;			//不要忘记这句！
		p->next = dummy2->next;
		return dummy1->next;
	}
};

#if 0
int main() {
	ListNode n0(1);
	ListNode n1(4);
	ListNode n2(3);
	ListNode n3(2);
	ListNode n4(5);
	ListNode n5(2);

	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	Solution s;
	int x;
	while (cin >> x) {
		ListNode *head = s.partition(&n0, x);
		while (head) {
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}
	return 0;
}
#endif