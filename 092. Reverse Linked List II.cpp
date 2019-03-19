//92. Reverse Linked List II
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
	ListNode * reverseBetween(ListNode* head, int m, int n) {
		if (head == nullptr) return nullptr;
		if (m >= n) return head;
		ListNode *prev = nullptr, *curr = head;
		while (m > 1) {
			prev = curr;
			curr = curr->next;
			m--;
			n--;
		}
		ListNode *tail = curr, *con = prev;
		prev = nullptr;
		while (n--) {
			ListNode *tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
		if (con != nullptr) {
			con->next = prev;
		}
		else {
			head = prev;
		}
		tail->next = curr;
		return head;
	}
};