//543. Diameter of Binary Tree
//Easy

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
	int diameterOfBinaryTree(TreeNode* root) {
		if (root == nullptr) return 0;
		//若没有下面两行，直接return，会stack overflow...I don't know why...
		if (root->left == nullptr) return heightOfBinaryTree(root->right);
		if (root->right == nullptr) return heightOfBinaryTree(root->left);
		return max(max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)), heightOfBinaryTree(root->left) + heightOfBinaryTree(root->right));
	}
	int heightOfBinaryTree(TreeNode* root) {
		if (root == nullptr) return 0;
		return 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
	}
};


class Solution_1 {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		int ret = 0;
		height(root, ret);
		return ret;
	}
	int height(TreeNode* root, int& ret) {
		if (root == nullptr) return 0;
		int left = height(root->left, ret);
		int right = height(root->right, ret);
		ret = max(ret, left + right);
		return max(left, right) + 1;
	}
};