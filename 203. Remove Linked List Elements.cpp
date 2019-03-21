//203. Remove Linked List Elements
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
	ListNode * removeElements(ListNode* head, int val) {
		if (head == nullptr) return nullptr;
		ListNode *dummyHead = new ListNode(0);
		ListNode *curr = head, *prev = dummyHead;
		while (curr != nullptr) {
			if (curr->val != val) {
				prev->next = curr;
				prev = curr;
			}
			curr = curr->next;
		}
		prev->next = nullptr;	
		return dummyHead->next;
	}
};