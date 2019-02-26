//112. Path Sum
//Easy


#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (root == nullptr) return false;
		if (root->left == nullptr && root->right == nullptr) return sum == root->val;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}

	bool hasPathSum(TreeNode* root, int sum){
		return root && ((!root->left && !root->right&&root->val == sum) || hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
	}
};