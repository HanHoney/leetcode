//82. Remove Duplicates from Sorted List II
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

	//¢ÙµÝ¹é
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *p = head->next;
		if (head->val == p->val) {
			while (p&&p->val == head->val) {
				p = p->next;
			}
			return deleteDuplicates(p);
		}
		else {
			head->next = deleteDuplicates(p);
			return head;
		}
	}

	//¢Úµü´ú
	ListNode* deleteDuplicates1(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode newHead = ListNode(INT_MIN);
		newHead.next = head;
		ListNode *prev = &newHead;
		ListNode *curr = head;
		while (curr) {
			bool duplicated = false;
			while (curr->next&&curr->val == curr->next->val) {
				duplicated = true;
				curr = curr->next;
			}
			if (duplicated) {
				curr = curr->next;
				continue;
			}
			prev->next = curr;
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr;
		return newHead.next;
	}
};

int main() {
	ListNode n0(1);
	ListNode n1(2);
	ListNode n2(3);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(4);
	ListNode n6(5);

	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;

	Solution s;
	ListNode *head = s.deleteDuplicates1(&n0);

	while (head) {
		cout << head->val << " ";
		head = head->next;			
	}
	cout << endl;
	system("pause");
	return 0;
}