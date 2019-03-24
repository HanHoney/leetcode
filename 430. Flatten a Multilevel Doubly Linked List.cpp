//430. Flatten a Multilevel Doubly Linked List
//Medium

class Node {
public:
	int val;
	Node *prev;
	Node *next;
	Node *child;
	Node() {}
	Node(int _val, Node* _prev, Node* _next, Node* _child) {
		val = _val;
		prev = _prev;
		next = _next;
		child = _child;
	}
};

class Solution {
public:
	Node * flatten(Node* head) {
		if (head == nullptr) return nullptr;
		Node *curr = head;
		while (curr->next != nullptr && curr->child == nullptr) {	//注意条件
			curr = curr->next;
		}
		Node *pNext = curr->next;
		pNext = flatten(pNext);
		Node *pChild = curr->child;
		pChild = flatten(pChild);
		curr->next = pChild;
		curr->child = nullptr;
		if (pChild != nullptr) pChild->prev = curr;			//注意if条件
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = pNext;
		if (pNext != nullptr) pNext->prev = curr;
		return head;
	}
};
