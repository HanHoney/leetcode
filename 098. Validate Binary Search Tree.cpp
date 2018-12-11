//98. Validate Binary Search Tree
//Medium
//BST的合法性判断
//【注意】右支左叶子结点还要与上上层结点比较，每个结点判断其是否在指定范围
//①递归判断 ②中序遍历，判断数组

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/*
	bool isValidBST(TreeNode *root) {
		return isValidBST(root, false, false, 0, 0);
	}
	bool isValidBST(TreeNode *root, bool hasLower, bool hasUpper, int lower, int upper)
	{
		if (!root) return true;
		else if ((hasLower && root->val <= lower) || (hasUpper && root->val >= upper)) return false;
		else return isValidBST(root->left, hasLower, true, lower, root->val) && isValidBST(root->right, true, hasUpper, root->val, upper);
	}
	*/

	//方法①
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}
	bool isValidBST(TreeNode *root, long long lower, long long upper) {
		if (!root) return true;
		return root->val > lower && root->val < upper && isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
	}

	//方法②
	bool isValidBST1(TreeNode* root) {
		if (!root) return true;
		vector<int> vals;
		inorder(root, vals);
		for (int i = 0; i < vals.size() - 1; i++) {
			if (vals[i] >= vals[i + 1]) return false;
		}
		return true;
	}
	void inorder(TreeNode *root,vector<int> &vals) {
		if (!root) return;
		inorder(root->left, vals);
		vals.push_back(root->val);
		inorder(root->right, vals);
	}
};