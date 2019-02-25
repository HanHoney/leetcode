//337. House Robber III
//Medium
//Ê÷ÐÎ¶¯¹æ

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	/*
	int f(TreeNode *root) {
		if (root == nullptr) return 0;
		return max(g(root), root->val + g(root->left) + g(root->right));
	}
	int g(TreeNode *root) {
		if (root == nullptr) return 0;
		return f(root->left) + f(root->right);
	}
	*/

	int rob(TreeNode *root) {
		if (root == nullptr) return 0;
		int val = root->val;
		if (root->left != nullptr) {
			val += rob(root->left->left) + rob(root->left->right);
		}
		if (root->right != nullptr) {
			val += rob(root->right->left) + rob(root->right->right);
		}
		return max(val, rob(root->left) + rob(root->right));
	}
};