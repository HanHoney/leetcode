//160. Intersection of Two Linked Lists
//Easy
//①双指针 two-pass		
//	TC:O(m+n)	SC:O(1)
//②hash表 one-pass
//	TC:O(m+n)	SC:O(m) or O(n)

#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};
class Solution {
public:

	//②hash表
	ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr) return nullptr;
		unordered_set<ListNode*> m;
		ListNode *p = headA;
		while (p) {
			m.insert(p);
			p = p->next;
		}
		p = headB;
		while (p) {
			if (m.find(p) != m.end()) {
				return p;
			}
			p = p->next;
		}
		return nullptr;
	}

	//①双指针
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr) return nullptr;
		int l1 = 0, l2 = 0;
		ListNode *pA = headA, *pB = headB;
		while (pA) {
			l1++;
			pA = pA->next;
		}
		while (pB) {
			l2++;
			pB = pB->next;
		}
		return l1 >= l2 ? helper(headA, headB, l1 - l2) : helper(headB, headA, l2 - l1);
	}
private:
	//L1长度不短于L2
	static ListNode *helper(ListNode *headA, ListNode *headB, int n) {
		ListNode *p = headA, *q = headB;
		while (n--) {
			p = p->next;
		}
		while (p != q) {
			p = p->next;
			q = q->next;
		}
		return p;
	}
};

//
//int main() {
//	ListNode n0(0);
//	ListNode n1(1);
//	ListNode n2(2);
//	ListNode n3(3);
//	ListNode n4(4);
//	ListNode n5(5);
//	n0.next = &n1;
//	n1.next = &n2;
//	n2.next = &n5;
//	n3.next = &n4;
//	n4.next = &n5;
//	ListNode *ans, *ans1;
//	Solution s;
//	ans = s.getIntersectionNode(&n0, &n3);
//	cout << (ans == nullptr ? -1 : ans->val) << endl;
//	ans1 = s.getIntersectionNode1(&n0, &n3);
//	cout << (ans == nullptr ? -1 : ans->val) << endl;
//	system("pause");
//	return 0;
//}