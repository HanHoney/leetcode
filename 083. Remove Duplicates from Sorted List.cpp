//83. Remove Duplicates from Sorted List
//Easy

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *prev = head;
		ListNode *curr = head->next;
		while (curr) {
			if (curr->val == prev->val) {
				prev->next = curr->next;
		//		delete curr;   使用new分配才用delete撤销
			}
			else {
				prev = curr;
			}
			curr = prev->next;
		}
		return head;
	}
};

int main() {
	ListNode n0(0);
	ListNode n1(1);
	ListNode n2(1);
	ListNode n3(2);
	ListNode n4(3);
	ListNode n5(3);

	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	Solution s;
	ListNode *head = s.deleteDuplicates(&n0);

	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	system("pause");
	return 0;
}