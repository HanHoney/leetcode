//117. Populating Next Right Pointers in Each Node II
//Medium

#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node() {}
	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class Solution {
public:
	Node * connect(Node* root) {
		if (root == nullptr) return nullptr;
		queue<Node*> q;
		q.push(root);
		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i<n; i++) {
				Node* curr = q.front();
				q.pop();
				if (i != n - 1) {
					curr->next = q.front();
				}
				else {
					curr->next = nullptr;
				}	//可以没有else判断分支，默认next为nullptr
				if (curr->left) {
					q.push(curr->left);
				}
				if (curr->right) {
					q.push(curr->right);
				}
			}
		}
		return root;
	}
};