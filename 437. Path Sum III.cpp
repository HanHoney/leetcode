//437. Path Sum III
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
	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr) return 0;
		return pathSumFromRoot(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
	int pathSumFromRoot(TreeNode* root, int sum) {
		if (root == nullptr) return 0;
		return (sum == root->val ? 1 : 0) + pathSumFromRoot(root->left, sum - root->val) + pathSumFromRoot(root->right, sum - root->val);
	}
};