//61. Rotate List
//Medium

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode * rotateRight(ListNode* head, int k) {
		if (head == nullptr || head->next == nullptr || k == 0) return head;
		ListNode *curr = head;
		int len = 1;
		while (curr->next != nullptr) { //求长度
			len++;
			curr = curr->next;
		}
		curr->next = head;              //首尾相连
		k %= len;
		int m = len - k;                //在第m个结点处断链
		for (int i = 0; i < m; i++) {
			curr = curr->next;
		}
		head = curr->next;            //记下新的头结点
		curr->next = nullptr;         //断环
		return head;
	}
};