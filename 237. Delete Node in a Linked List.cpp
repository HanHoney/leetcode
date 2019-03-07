//237. Delete Node in a Linked List
//Easy

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		int tmp = node->next->val;
		node->next = node->next->next;
		node->val = tmp;
	}
};