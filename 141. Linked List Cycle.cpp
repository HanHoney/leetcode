//141. Linked List Cycle
//Easy
//˫ָ�뷨
//TC:O(n)	SC:O(1)

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr) return false;
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast != nullptr&&fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) return true;
		}
		return false;
	}
};