//138. Copy List with Random Pointer
//Medium
//剑指offer第26题
//TC:O(n)   SC:O(1)

#include <iostream>
using namespace std;

class Node {
public:
	int val;
	Node *next;
	Node *random;
	Node(){}
	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr) return nullptr;
		Node *curr = head;
		while (curr != nullptr) {
			Node *copy = new Node(curr->val, curr->next, nullptr);
			curr->next = copy;
			curr = copy->next;
		}
		curr = head;
		while (curr != nullptr) {   //结点个数为偶数
			if (curr->random != nullptr) {
				curr->next->random = curr->random->next;
			}
			curr = curr->next->next;
		}
		Node *copyHead = head->next;
		curr = head;
		while (curr != nullptr) {
			Node *tmp = curr->next;
			curr->next = tmp->next;
			if (curr->next) {
				tmp->next = curr->next->next;
			}
			curr = curr->next;
		}
		return copyHead;
	}
};