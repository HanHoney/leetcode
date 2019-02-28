//145. Binary Tree Postorder Traversal
//Hard

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
#if 0
	//递归
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		postorderTraversal(root, ret);
		return ret;
	}
	void postorderTraversal(TreeNode* root, vector<int>& ret) {
		if (root == nullptr) return;
		postorderTraversal(root->left, ret);
		postorderTraversal(root->right, ret);
		ret.push_back(root->val);
	}
#endif
	//迭代
	//使用2个stack
	vector<int> postorderTraversal_twoStacks(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr) return ret;
		stack<TreeNode*> s1, s2;
		s1.push(root);
		while (!s1.empty()) {
			TreeNode *curr = s1.top();
			s1.pop();
			s2.push(curr);
			if (curr->left) {
				s1.push(curr->left);
			}
			if (curr->right) {
				s1.push(curr->right);
			}
		}
		while (!s2.empty()) {
			ret.push_back(s2.top()->val);
			s2.pop();
		}
		return ret;
	}

	//使用1个stack
	vector<int> postorderTraversal_oneStack(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr) return ret;
		stack<TreeNode*> s;
		s.push(root);
		TreeNode *prev, *curr;
		while (!s.empty()) {
			curr = s.top();
			if (curr->left&&prev != curr->left&&prev != curr->right) {
				s.push(curr->left);
			}
			else if (curr->right&&prev != curr->right) {
				s.push(curr->right);
			}
			else {
				ret.push_back(curr->val);
				s.pop();
				prev = curr;
			}
		}
		return ret;
	}
};