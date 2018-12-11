// 25. Reverse Nodes in k-Group
// Hard
// 单链表逆序问题的扩展，借助空节点，依次改变指针方向
// 递归

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
		ListNode* curr = head;   //当前节点
		ListNode* pre = NULL;    //前驱节点指针，指向空节点
		while (curr != nextHead) {  
			ListNode*tmp = curr->next;
			curr->next = pre ? pre : nextGroup;
			pre = curr;
			curr = tmp;
		}
		return pre;
	}
};