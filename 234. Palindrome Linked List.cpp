//234. Palindrome Linked List
//Easy
//two pointers
//TC:O(n)  SC:O(1)


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
	bool isPalindrome(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return true;
		ListNode *p, *q;
		p = head;
		q = head->next;
		while (q&&q->next) {
			p = p->next;
			q = q->next->next;
		}
		p = p->next;
		q = reverseList(p);
		p = head;
		while (p&&q) {
			if (p->val != q->val) return false;
			p = p->next;
			q = q->next;
		}
		return true;
	}

private:
	static ListNode *reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *tmp = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return tmp;
	}
	static ListNode *reverseList1(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *curr = head;
		ListNode *prev = nullptr;
		while (curr) {
			ListNode *tmp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = tmp;
		}
		return prev;
	}
};

int main() {
	ListNode n0(0);
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(2);
	ListNode n4(1);
	ListNode n5(0);
	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	Solution s;
	cout << s.isPalindrome(&n0) << endl;
	system("pause");
	return 0;
}
