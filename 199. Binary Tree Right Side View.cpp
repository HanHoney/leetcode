//199. Binary Tree Right Side View
//Medium

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr) return ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int n = q.size();
			ret.push_back(q.back()->val);
			for (int i = 0; i < n; i++) {
				TreeNode *curr = q.front();
				q.pop();
				if (curr->left) q.push(curr->left);
				if (curr->right) q.push(curr->right);
			}
		}
		return ret;
	}
};