//817. Linked List Components
//Medium

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		if (G.size() == 1) return 1;
		unordered_set<int> mySet(G.begin(), G.end());
		int ret = 0;
		ListNode *curr = head, *prev = nullptr;
		while (curr != nullptr) {
			if (mySet.find(curr->val) != mySet.end() && (prev == nullptr || mySet.find(prev->val) == mySet.end())) {
				ret++;
			}
			prev = curr;
			curr = curr->next;
		}
		return ret;
	}
};