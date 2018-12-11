//141. Linked List Cycle
//Easy
//双指针法
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
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return false;
		ListNode *p, *q;
		p = head;		//每次走一步
		q = head->next;    //每次走两步
		while (q!=p) {  //若相遇，则跳出循环，return true
			if (q == NULL || q->next == NULL) return false;
			p = p->next;
			q = q->next->next;  //跳两步，若无圈，则最后一次skip直接跳到nullptr或者最后一个节点
		}
		return true;
	}

	bool hasCycle1(ListNode *head) {
		if (head == NULL || head->next == NULL) return false;
		ListNode *p, *q;
		p = head;
		q = head;
		while (q&&q->next) {
			p = p->next;
			q = q->next->next;
			if (p == q) return true;
		}
		return false;
	}
};