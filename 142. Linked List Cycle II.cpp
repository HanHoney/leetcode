//142. Linked List Cycle II
//Medium
//˫ָ�뷨������P141
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
		if (head == NULL || head->next == NULL) return NULL;
		ListNode *p = head, *q = head;
		while (q&&q->next) {
			p = p->next;
			q = q->next->next;
			if (p == q) {		//��Ȧ�������ҿ�ʼλ��
				q = head;
				while (p != q) {
					p = p->next;
					q = q->next;
				}
				return p;
			}
		}
		return NULL;
	}
};