//236. Lowest Common Ancestor of a Binary Tree
//Medium
//LCA 最近公共祖先

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
	TreeNode *lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || p == nullptr || q == nullptr) return nullptr;
		if (root == p || root == q) return root;
		TreeNode *l = lowestCommonAncestor(root->left, p, q);
		TreeNode *r = lowestCommonAncestor(root->right, p, q);
		if (l&&r) return root;
		return l ? l : r;
	}
};