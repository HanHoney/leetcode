//105. Construct Binary Tree from Preorder and Inorder Traversal
//Medium
//根据先序遍历和中序遍历构造二叉树

#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
	
	TreeNode* buildTree_1(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return NULL;
		if (preorder.size() == 1) return new TreeNode(preorder[0]);
		int iroot = preorder[0];
		int ipos = 0;
		for (int i = 0; i < inorder.size(); i++) {
			if (inorder[i] == iroot) {
				ipos = i;
				break;
			}
		}
		//左子树ipos个结点
		TreeNode *root = new TreeNode(iroot);
		vector<int> v1(preorder.begin() + 1, preorder.begin() + ipos + 1);
		vector<int> v2(inorder.begin(), inorder.begin() + ipos);
		vector<int> v3(preorder.begin() + ipos + 1, preorder.end());
		vector<int> v4(inorder.begin() + ipos + 1, inorder.end());
		root->left = buildTree_1(v1, v2);
		root->right = buildTree_1(v3, v4);
		return root;
	}
	
	////////////
	/***********
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right, int& index)
	{
		if (left > right)
			return NULL;

		int j;
		for (int i = left; i <= right; i++)
		{
			if (inorder[i] == preorder[index])
			{
				j = i;
				break;
			}
		}

		TreeNode* t = new TreeNode(preorder[index++]);
		t->left = build(preorder, inorder, left, j-1, index);
		t->right = build(preorder, inorder, j+1, right, index);

		return t;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int i = 0;
		return build(preorder, inorder, 0, inorder.size()-1, i);
	}
	*************************/

	TreeNode* buildTree(vector<int>::iterator begin1, vector<int>::iterator end1, vector<int>::iterator begin2, vector<int>::iterator end2) {
		if (begin1 >= end1 || begin2 >= end2) return nullptr;
		TreeNode *root = new TreeNode(*begin1);   //iterator和指针同用法
		vector<int>::iterator it = find(begin2, end2, *begin1);
		int len = it - begin2;
		root->left = buildTree(begin1 + 1, begin1 + len + 1, begin2, it);
		root->right = buildTree(begin1 + len + 1, end1, it + 1, end2);
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
};