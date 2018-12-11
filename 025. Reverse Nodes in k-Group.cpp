// 25. Reverse Nodes in k-Group
// Hard
// �����������������չ�������սڵ㣬���θı�ָ�뷽��
// �ݹ�

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * reverseKGroup(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k == 1) return head;
		ListNode* nextHead = head;
		for (int i = 0; i < k; i++) {
			if (nextHead) {
				nextHead = nextHead->next;
			}
			else return head;
		}
		ListNode* nextGroup = reverseKGroup(nextHead, k);
		ListNode* curr = head;   //��ǰ�ڵ�
		ListNode* pre = NULL;    //ǰ���ڵ�ָ�룬ָ��սڵ�
		while (curr != nextHead) {  
			ListNode*tmp = curr->next;
			curr->next = pre ? pre : nextGroup;
			pre = curr;
			curr = tmp;
		}
		return pre;
	}
};