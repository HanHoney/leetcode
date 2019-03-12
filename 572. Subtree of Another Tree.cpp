//572. Subtree of Another Tree
//Easy

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (s == nullptr) return t == nullptr;
		return isHomogeneous(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
	}
	bool isHomogeneous(TreeNode* s, TreeNode* t) {
		if (s == nullptr || t == nullptr) return s == t;
		if (s->val != t->val) return false;
		return isHomogeneous(s->left, t->left) && isHomogeneous(s->right, t->right);
	}
};