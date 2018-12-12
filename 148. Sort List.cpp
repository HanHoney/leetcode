//148. Sort List
//Medium
//TC:O(nlogn)	SC:O(1)
//���á�21. Merge Two Sorted Lists��
/************
MergeSort
S1.����Ͽ����ֳ�����
S2.����������ֱ�����
S3.merge
************/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode *middle = findMiddle(head);
		ListNode *head2 = middle->next;
		middle->next = nullptr;		//����
		ListNode *l1 = sortList(head);
		ListNode *l2 = sortList(head2);
		return mergeTwoLists(l1, l2);
	}

private:
	//˫ָ�����м�ڵ�
	
	static ListNode *findMiddle(ListNode* head) {
		if (head == nullptr) return nullptr;
		ListNode *p = head;
		ListNode *q = head->next;

	//	ListNode *q = head;            //���󣡣���RunTime Error
	/*********************************************************************
	������middle�������
	��ListNode *q = head->next;
	��������������Ϊ(L,L-1)����(L,L)���������շֵ�����������С����

	Ȼ������ListNode *q = head;
	������������Ϊ(L,L-2)��(L,L-1)������Ϊż��ʱ��ǰһ���������С�������ȷֱ�Ϊ2��0�����ܻ��������ڵ㣬����Զѭ����ȥ��

	for instance:
	������һ����������㣬һ��ѭ����p�ߵ��ڶ�����㣬q�ߵ�NULL������ѭ�������ص�p��ָ��ڶ����ڵ��ָ�롣��sortList�У�������Ϊ����2�ͳ���0������������������ѭ����
	**********************************************************************/

		while (q&&q->next) {
			p = p->next;
			q = q->next->next;
		}
		return p;

	}

	static ListNode *mergeTwoLists(ListNode* l1, ListNode *l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		ListNode headNode(-1);
		ListNode *p = &headNode;
		while (l1&&l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		p->next = l1 == nullptr ? l2 : l1;	//����Ϊ0��ĩβָ��nullptr
		return headNode.next;
	}
};

