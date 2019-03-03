//138. Copy List with Random Pointer
//Medium
//Ω£÷∏offer26Ã‚
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
		Node* curr = head;
		while (curr != nullptr) {
			Node *tmp = new Node();
			tmp->val = curr->val;
			tmp->next = curr->next;
			tmp->random = nullptr;
			curr->next = tmp;
			curr = tmp->next;
		}
		curr = head;
		while (curr != nullptr) {
			Node *tmp = curr->next;
			if (curr->random) {
				tmp->random = curr->random->next;
			}
			curr = tmp->next;
		}
		curr = head;
		Node *copyHead = head->next;
		while (curr != nullptr) {
			Node* tmp = curr->next;
			curr->next = tmp->next;
			if (curr->next) {
				tmp->next = curr->next->next;
			}
			else {
				tmp->next = nullptr;
			}
			curr = curr->next;
		}
		return copyHead;
	}
};