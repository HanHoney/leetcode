//133. Clone Graph
//Medium
//BFS ¹þÏ£±í

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	Node * cloneGraph(Node* node) {
		if (node == nullptr) return nullptr;
		unordered_map<Node*, Node*> map;
		Node *copy = new Node(node->val);
		map[node] = copy;
		queue<Node*> q;
		q.push(node);
		while (!q.empty()) {
			Node *curr = q.front();
			q.pop();
			vector<Node*> vec = curr->neighbors;
			for (auto i : vec) {
				if (map.find(i) == map.end()) {
					map[i] = new Node(i->val);
					q.push(i);
				}
				map[curr]->neighbors.push_back(map[i]);
			}
		}
		return copy;
	}
};