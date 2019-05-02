//142. Linked List Cycle II
//Medium
//双指针法，基于P141
//TC:O(n)	SC:O(1)

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * detectCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return nullptr;
		ListNode *slow = head, *fast = head;
		while (fast&&fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				fast = head;
				while (slow != fast) {
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
		return nullptr;
	}
};