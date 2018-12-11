//19. Remove Nth Node From End of List
//��˫ָ�뷨��
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
		ListNode newHead(0);       //�µ�ͷ��㣬��Ϊhead���ܱ��Ƴ�
		newHead.next = head;
		head = &newHead;
		ListNode *p, *q;
		p = q = head;
		for (int i = 0; i < n; i++) {   //ָ��p����n��
			if (p->next == NULL) return NULL;
			p = p->next;
		}
		while (p->next != NULL) {
			p = p->next;
			q = q->next;
		}
		//ɾ��q����һ��Ԫ�أ�
		q->next = q->next->next;
		return head->next;
	}
};