//445. Add Two Numbers II
//Medium

//① 反转链表
//② 利用stack
//③ 先求长,尾部对齐

#include <iostream>
#include <stack>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head1 = reverseList(l1);
		ListNode *head2 = reverseList(l2);
		ListNode *p1 = head1, *p2 = head2;
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		int carry = 0;
		while (p1 != nullptr || p2 != nullptr) {
			int sum = carry;
			if (p1 != nullptr) {
				sum += p1->val;
				p1 = p1->next;
			}
			if (p2 != nullptr) {
				sum += p2->val;
				p2 = p2->next;
			}
			p->next = new ListNode(sum % 10);
			p = p->next;
			carry = sum / 10;
		}
		if (carry) {
			p->next = new ListNode(carry);
			p = p->next;
		}
		return reverseList(head->next);
	}
	ListNode* reverseList(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *curr = head, *prev = nullptr;
		while (curr != nullptr) {
			ListNode *tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
		return prev;
	}


	ListNode* addTwoNumbersWithStack(ListNode* l1, ListNode* l2) {
		stack<int> s1, s2;
		ListNode *p1 = l1, *p2 = l2;
		while (p1 != nullptr) {
			s1.push(p1->val);
			p1 = p1->next;
		}
		while (p2 != nullptr) {
			s2.push(p2->val);
			p2 = p2->next;
		}
		int carry = 0;
		ListNode *head = new ListNode(0);
		while (!s1.empty() || !s2.empty()) {
			int sum = carry;
			if (!s1.empty()) {
				sum += s1.top();
				s1.pop();
			}
			if (!s2.empty()) {
				sum += s2.top();
				s2.pop();
			}
			ListNode *curr = new ListNode(sum % 10);
			carry = sum / 10;
			ListNode *tmp = head->next;
			head->next = curr;
			curr->next = tmp;
		}
		if (carry) {
			head->val = carry;
			return head;
		}
		else return head->next;
	}
};