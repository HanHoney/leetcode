//141. Linked List Cycle
//Easy
//˫ָ�뷨
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
		p = head;		//ÿ����һ��
		q = head->next;    //ÿ��������
		while (q!=p) {  //��������������ѭ����return true
			if (q == NULL || q->next == NULL) return false;
			p = p->next;
			q = q->next->next;  //������������Ȧ�������һ��skipֱ������nullptr�������һ���ڵ�
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