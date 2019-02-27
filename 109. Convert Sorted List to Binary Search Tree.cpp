//109. Convert Sorted List to Binary Search Tree
//Medium

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

//TC:O(nlogn)	SC:O(logn)
class Solution_1 {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return new TreeNode(head->val);
		ListNode *mid = cutAtMiddle(head);
		TreeNode *root = new TreeNode(mid->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(mid->next);
		return root;
	}
	ListNode *cutAtMiddle(ListNode *head) {
		if (head == nullptr) return nullptr;
		ListNode *prev = head;
		ListNode *fast = head;			//×ó×ÓÊ÷´ó
		ListNode *slow = head;
		while (fast&&fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		//¶ÏÁ´
		prev->next = nullptr;
		return slow;
	}
};