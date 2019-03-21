//725. Split Linked List in Parts
//Medium

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {}
};

class Solution {
public:
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector<ListNode*> ret(k, nullptr);
		if (root == nullptr) return ret;
		int len = 0;
		ListNode *curr = root;
		while (curr != nullptr) {
			len++;
			curr = curr->next;
		}
		int n = len / k;
		int r = len % k;
		curr = root;
		ListNode *prev = nullptr;
		for (int i = 0; curr != nullptr && i < k; i++, r--) {
			ret[i] = curr;
			for (int j = 0; j < n + (r > 0); j++) {
				prev = curr;
				curr = curr->next;
			}
			prev->next = nullptr;
		}
		return ret;
	}
};