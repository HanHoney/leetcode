//98. Validate Binary Search Tree
//Medium
//BST�ĺϷ����ж�
//��ע�⡿��֧��Ҷ�ӽ�㻹Ҫ�����ϲ���Ƚϣ�ÿ������ж����Ƿ���ָ����Χ
//�ٵݹ��ж� ������������ж�����

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

	//������
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LONG_MIN, LONG_MAX);
	}
	bool isValidBST(TreeNode *root, long long lower, long long upper) {
		if (!root) return true;
		return root->val > lower && root->val < upper && isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
	}

	//������
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