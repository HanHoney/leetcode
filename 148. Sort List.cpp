//148. Sort List
//Medium
//TC:O(nlogn)	SC:O(1)
//复用【21. Merge Two Sorted Lists】
/************
MergeSort
S1.链表断开，分成两半
S2.两个子链表分别排序
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
		middle->next = nullptr;		//断链
		ListNode *l1 = sortList(head);
		ListNode *l2 = sortList(head2);
		return mergeTwoLists(l1, l2);
	}

private:
	//双指针找中间节点
	
	static ListNode *findMiddle(ListNode* head) {
		if (head == nullptr) return nullptr;
		ListNode *p = head;
		ListNode *q = head->next;

	//	ListNode *q = head;            //错误！！！RunTime Error
	/*********************************************************************
	最终在middle后面断链
	若ListNode *q = head->next;
	则两个子链长度为(L,L-1)或者(L,L)，可以最终分到单个结点的最小子链

	然而，若ListNode *q = head;
	两个子链长度为(L,L-2)或(L,L-1)，链长为偶数时是前一种情况，最小子链长度分别为2和0，不能划分至单节点，将永远循环下去。

	for instance:
	链表中一共有两个结点，一次循环后，p走到第二个结点，q走到NULL，跳出循环，返回的p是指向第二个节点的指针。在sortList中，链表会断为长度2和长度0的两个子链表。程序死循环。
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
		p->next = l1 == nullptr ? l2 : l1;	//若都为0，末尾指向nullptr
		return headNode.next;
	}
};

