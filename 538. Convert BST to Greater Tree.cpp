//538. Convert BST to Greater Tree
//Easy

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* convertBST(TreeNode* root) {
		if (root == nullptr) return nullptr;
		int sum = 0;
		inorderTraversal(root, sum);
		return root;
	}
	void inorderTraversal(TreeNode* root, int& sum) {
		if (root == nullptr) return;
		inorderTraversal(root->right, sum);
		root->val += sum;
		sum = root->val;
		inorderTraversal(root->left, sum);
	}
};