//206. Reverse Linked List
//Easy
//¢Ùµü´ú ¢ÚµÝ¹é

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:

	//Approach #1(Iterative)
	//TC:O(n)  SC:O(1)
	ListNode* reverseList(ListNode* head) {
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

	//Approach #2(Recursive)
	//TC:O(n)  SC:O(n)¡¾µÝ¹éµ¼ÖÂµÄÒþÐÎ¶ÑÕ»Ê½¿Õ¼ä¡¿
	ListNode* reverseList_1(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *p = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return p;
	}
};
