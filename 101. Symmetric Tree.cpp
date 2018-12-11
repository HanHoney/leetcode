//101. Symmetric Tree
//Easy

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
	bool isSymmetric(TreeNode *root) {
		if (root == NULL) return true;
		return check(root->left, root->right);
	}
	bool check(TreeNode *l, TreeNode *r) {
		if (l == NULL && r == NULL) return true;
		if (l == NULL || r == NULL) return false;
		if (l->val != r->val) return false;
		return check(l->left, r->right) && check(l->right, r->left);
	}

	/*
	TreeNode *createBinaryTree(vector<int> dates) {
		vector<TreeNode*> tree;
		for (auto a : dates) {
			tree.push_back(new TreeNode(a));
		}
		for (int i = 0, pos = 0; pos < tree.size() - 2; i++) {
			tree[i]->left = tree[++pos];
			tree[i]->right = tree[++pos];
		}
		return tree[0];
	}
	*/
};

//
//int main() {
//	TreeNode root(1);
//	TreeNode t2(2);
//	TreeNode t3(2);
//	TreeNode t4(3);
//	TreeNode t5(4);
//	TreeNode t6(4);
//	TreeNode t7(3);
//
//	root.left = &t2;
//	root.right = &t3;
//	t2.left = &t4;
//	t2.right = &t5;
//	t3.left = &t6;
//	t3.right = &t7;
//
//	vector<int> v1{ 1,2,2,3,4,4,3,5,6,7,8,8,7,6,5 };
//	vector<int> v2{ 1,2,2,-1,3,-1,3 };
//
//	Solution s;
//	cout << s.isSymmetric(s.createBinaryTree(v1)) << endl;
//	cout << s.isSymmetric(s.createBinaryTree(v2)) << endl;
//
//	system("pause");
//	return 0;
//}