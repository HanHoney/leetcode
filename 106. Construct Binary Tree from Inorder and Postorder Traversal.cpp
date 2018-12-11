//106. Construct Binary Tree from Inorder and Postorder Traversal
//Medium
//和P105一样~

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * buildTree(vector<int>::iterator begin1, vector<int>::iterator end1, vector<int>::iterator begin2, vector<int>::iterator end2) {
		if (begin1 >= end1 || begin2 >= end2) return nullptr;
		int valueOfRoot = *(end2 - 1);
		TreeNode *root = new TreeNode(valueOfRoot);   //iterator和指针同用法
		vector<int>::iterator it = find(begin1, end1, valueOfRoot);
		int lengthOfLeft = it - begin1;
		root->left = buildTree(begin1, it, begin2, begin2 + lengthOfLeft);
		root->right = buildTree(it + 1, end1, begin2 + lengthOfLeft, end2 - 1);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}
};