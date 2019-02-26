//226. Invert Binary Tree
//Easy

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
	//µÝ¹é
	TreeNode *invertTree(TreeNode* root) {
		if (root == nullptr) return nullptr;
		TreeNode *tmp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(tmp);
		return root;
	}

	//·ÇµÝ¹é£¬BFS
	TreeNode *invertTree(TreeNode* root) {
		if (root == nullptr) return nullptr;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode *curr = q.front();
			q.pop();
			if (curr->left) {
				q.push(curr->left);
			}
			if (curr->right) {
				q.push(curr->right);
			}
			swap(curr->left, curr->right);
		}
		return root;
	}
};