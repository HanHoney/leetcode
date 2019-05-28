//235. Lowest Common Ancestor of a Binary Search Tree
//Easy

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (p->val > q->val) return lowestCommonAncestor(root, q, p);
		if (p->val <= root->val&&q->val >= root->val) return root;
		else if (q->val < root->val) return lowestCommonAncestor(root->left, p, q);
		else return lowestCommonAncestor(root->right, p, q);
	}
};