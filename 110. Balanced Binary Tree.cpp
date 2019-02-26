//110. Balanced Binary Tree
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
	bool isBalanced(TreeNode* root) {
		return balancedHeight(root) >= 0;
	}
	//若不是平衡树，则返回-1
	int balancedHeight(TreeNode* root) {
		if (root == nullptr) return 0;
		int left = balancedHeight(root->left);
		int right = balancedHeight(root->right);
		if (left < 0 || right < 0 || abs(left - right)>1) return -1;
		return max(left, right) + 1;
	}
};