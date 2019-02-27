//99. Recover Binary Search Tree
//Hard
//改写中序遍历
//first:第一对逆序中的较大值 second:最后一对逆序中的最小值（可能有一对或两对逆序）
//SC:O(L) L为栈最大时的值

#include <iostream>
#include <limits.h>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

//非递归
class Solution_1 {
public:
	void recoverTree(TreeNode* root) {
		TreeNode *first = nullptr;
		TreeNode *second = nullptr;
		TreeNode *prev = new TreeNode(INT_MIN);
		TreeNode *curr = root;
		stack<TreeNode*> s;
		while (!s.empty() || curr) {
			if (curr) {
				s.push(curr);
				curr = curr->left;
			}
			else {
				curr = s.top();
				s.pop();
				if (prev->val >= curr->val) {
					if (!first) {
						first = prev;
					}
					second = curr;
				}
				prev = curr;
				curr = curr->right;
			}
		}
		swap(first->val, second->val);
	}
};

//递归
class Solution_2 {
	TreeNode *first = nullptr;
	TreeNode *second = nullptr;
	TreeNode *prev = new TreeNode(INT_MIN);
public:
	void recoverTree(TreeNode* root) {
		inorderTraversal(root);
		swap(first->val, second->val);
	}
	void inorderTraversal(TreeNode* root) {
		if (root == nullptr) return;
		inorderTraversal(root->left);
		if (prev->val >= root->val) {
			if (!first) {
				first = prev;
			}
			second = root;
		}
		prev = root;
		inorderTraversal(root->right);
	}
};
