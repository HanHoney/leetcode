//107. Binary Tree Level Order Traversal II
//Easy

#include <iostream>
#include <vector>
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == nullptr) return ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int n = q.size();
			vector<int> tmp;
			for (int i = 0; i<n; i++) {
				TreeNode *curr = q.front();
				tmp.push_back(curr->val);
				q.pop();
				if (curr->left) q.push(curr->left);
				if (curr->right) q.push(curr->right);
			}
		//  ret.insert(ret.begin(),tmp);  //²»Ðèreverse
			ret.push_back(tmp);
		}
		int l = 0, r = ret.size() - 1;
		while (l < r) {
			swap(ret[l++], ret[r--]);
		}
		return ret;
	}
};