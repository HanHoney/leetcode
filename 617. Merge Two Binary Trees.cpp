//617. Merge Two Binary Trees
//Easy

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	//开辟新的树，浪费空间
	TreeNode* mergeTrees1(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL) return t2;
		if (t2 == NULL) return t1;
		TreeNode *newNode = new TreeNode(t1->val + t2->val);   //声明不分配空间，new才分配空间。
		newNode->left = mergeTrees1(t1->left, t2->left);
		newNode->right = mergeTrees1(t1->right, t2->right);
		return newNode;
	}

	//in-place
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL) return t2;
		if (t2 == NULL) return t1;
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);
		return t1;
	}
};