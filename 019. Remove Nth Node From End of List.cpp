//19. Remove Nth Node From End of List
//【双指针法】
#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) {
		this->val = x;
		this->next = NULL;
	}
};
class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n <= 0) return NULL;
		ListNode newHead(0);       //新的头结点，因为head可能被移除
		newHead.next = head;
		head = &newHead;
		ListNode *p, *q;
		p = q = head;
		for (int i = 0; i < n; i++) {   //指针p先走n步
			if (p->next == NULL) return NULL;
			p = p->next;
		}
		while (p->next != NULL) {
			p = p->next;
			q = q->next;
		}
		//删除q的下一个元素；
		q->next = q->next->next;
		return head->next;
	}
};