//111. Minimum Depth of Binary Tree
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
	//注意，根节点不是叶节点
	int minDepth(TreeNode* root) {
		if (root == nullptr) return 0;
		if (root->left == nullptr) {
			return minDepth(root->right) + 1;
		}
		if (root->right == nullptr) {
			return minDepth(root->left) + 1;
		}
		return 1 + min(minDepth(root->left), minDepth(root->right));
	}
};