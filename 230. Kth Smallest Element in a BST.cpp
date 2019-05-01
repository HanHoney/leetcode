//230. Kth Smallest Element in a BST
//Medium

/*
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
How would you optimize the kthSmallest routine?

同时在节点中记录左子树大小的信心，插入和删除结点都要维护左子树的大小信息。
查找时间：O(h) h is the height of the tree 
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> s;
		TreeNode* curr = root;
		while (curr != nullptr || !s.empty()) {
			if (curr) {
				s.push(curr);
				curr = curr->left;
			}
			else {
				curr = s.top();
				s.pop();
				k--;
				if (k == 0) {
					return curr->val;
				}
				curr = curr->right;
			}
		}
		return -1;
	}
};

class Solution_1 {
public:
	int kthSmallest(TreeNode* root, int k) {
		vector<TreeNode*> nodes;
		helper(root, k, nodes);
		return nodes[k - 1]->val;
	}
	void helper(TreeNode* root, int k, vector<TreeNode*>& nodes) {
		if (root == nullptr) return;
		helper(root->left, k, nodes);
		if (nodes.size() >= k) return;
		nodes.emplace_back(root);
		if (nodes.size() >= k) return;
		helper(root->right, k, nodes);
	}
};

