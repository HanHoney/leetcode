//114. Flatten Binary Tree to Linked List
//Medium
//in-place
//按先序遍历展开 ①递归	②非递归

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

	//递归
	void flatten(TreeNode* root) {
		if (root == nullptr) return;
		flatten(root->left);
		flatten(root->right);
		if (root->left == nullptr) return;
		TreeNode *tmp = root->left;
		while (tmp->right) {
			tmp = tmp->right;
		}
		tmp->right = root->right;
		root->right = root->left;
		root->left = nullptr;		
	}


	//非递归
	void flatten1(TreeNode* root) {
		for (; root; root = root->right) {
			if (root->left) {
				TreeNode *prev = root->left;
				while (prev->right) {
					prev = prev->right;
				}
				prev->right = root->right;
				root->right = root->left;
				root->left = nullptr;
			}
		}
	}
};

//int main() {
//	TreeNode n1(1);
//	TreeNode n2(2);
//	TreeNode n3(3);
//	TreeNode n4(4);
//	TreeNode n5(5);
//	TreeNode n6(6);
//	n1.left = &n2;
//	n1.right = &n5;
//	n2.left = &n3;
//	n2.right = &n4;
//	n5.right = &n6;
//	Solution s;
//	s.flatten(&n1);
//	for (TreeNode *p = &n1; p; p = p->right) {
//		cout << p->val << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}