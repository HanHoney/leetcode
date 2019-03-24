//129. Sum Root to Leaf Numbers
//Medium

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
	int sumNumbers(TreeNode* root) {
		if (root == nullptr) return 0;
		int ret = 0;
		dfs(root->val, root, ret);
		return ret;
	}
private:
	static void dfs(int pathSum, TreeNode* curr, int& totalSum) {
		if (curr->left == nullptr && curr->right == nullptr) {
			totalSum += pathSum;
		}
		if (curr->left != nullptr) {
			dfs(10 * pathSum + curr->left->val, curr->left, totalSum);
		}
		if (curr->right != nullptr) {
			dfs(10 * pathSum + curr->right->val, curr->right, totalSum);
		}
	}
};