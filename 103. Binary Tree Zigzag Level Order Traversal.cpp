//103. Binary Tree Zigzag Level Order Traversal
//Medium
//之字形打印二叉树

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	
	//也可以使用2个stack实现
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == nullptr) return ret;
		queue<TreeNode*> q;
		q.push(root);
		bool oddLevel = true;	//记录当前层是否为奇数层
		while (!q.empty()) {
			int n = q.size();
			vector<int> tmp(n);
			if (oddLevel) {
				for (int i = 0; i<n; i++) {
					TreeNode *curr = q.front();
					tmp[i] = curr->val;
					q.pop();
					if (curr->left) q.push(curr->left);
					if (curr->right) q.push(curr->right);
				}
			}
			else {
				for (int i = n - 1; i >= 0; i--) {
					TreeNode *curr = q.front();
					tmp[i] = curr->val;
					q.pop();
					if (curr->left) q.push(curr->left);
					if (curr->right) q.push(curr->right);
				}
			}
			oddLevel = !oddLevel;
			ret.push_back(tmp);
		}
		return ret;
	}
};

#if 0
class Solution {
	stack<TreeNode*> stack1;
	stack<TreeNode*> stack2;
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int>> res;
		if (pRoot == nullptr) return res;
		stack1.push(pRoot);
		while (!stack1.empty() || !stack2.empty()) {
			vector<int> tmp1, tmp2;
			while (!stack1.empty()) {
				TreeNode* curr = stack1.top();
				tmp1.push_back(curr->val);
				if (curr->left) stack2.push(curr->left);
				if (curr->right) stack2.push(curr->right);
				stack1.pop();
			}
			if (!tmp1.empty()) res.push_back(tmp1);
			while (!stack2.empty()) {
				TreeNode* curr = stack2.top();
				tmp2.push_back(curr->val);
				if (curr->right) stack1.push(curr->right);
				if (curr->left) stack1.push(curr->left);
				stack2.pop();
			}
			if (!tmp2.empty()) res.push_back(tmp2);
		}
		return res;
	}

};
#endif