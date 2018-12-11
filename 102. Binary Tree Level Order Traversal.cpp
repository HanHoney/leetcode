//102. Binary Tree Level Order Traversal
//Medium
//二叉树层序遍历

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == NULL) return ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();   //当前层的结点个数
			vector<int> tmp;
			for (int i = 0; i < size; i++) {
				TreeNode* node = q.front();
				tmp.push_back(node->val);
				q.pop();
				if (node->left != NULL) q.push(node->left);
				if (node->right != NULL) q.push(node->right);
			}
			ret.push_back(tmp);
		}
		return ret;
	}
};