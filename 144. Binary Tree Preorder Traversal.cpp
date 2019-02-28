//144. Binary Tree Preorder Traversal
//Medium

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
#if 1
	//递归
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		preorderTraversal(root, ret);
		return ret;
	}
	void preorderTraversal(TreeNode* root, vector<int>& ret) {
		if (root == nullptr) return;
		ret.push_back(root->val);
		preorderTraversal(root->left, ret);
		preorderTraversal(root->right, ret);
	}
#endif
	//迭代
	//利用stack，先push right，再push left
	vector<int> preorderTraversal_it(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr) return ret;
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty()) {
			TreeNode *curr = s.top();
			ret.push_back(curr->val);
			s.pop();
			if (curr->right != nullptr) {
				s.push(curr->right);
			}
			if (curr->left != nullptr) {
				s.push(curr->left);
			}
		}
		return ret;
	}
};