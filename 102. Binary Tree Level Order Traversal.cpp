//102. Binary Tree Level Order Traversal
//Medium
//�������������

#include <iostream>
#include <vector>
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;
		if (root == nullptr) return ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int size = q.size();   //��ǰ��Ľ�����
			vector<int> tmp;
			for (int i = 0; i < size; i++) {
				TreeNode* node = q.front();
				tmp.push_back(node->val);
				q.pop();
				if (node->left != nullptr) q.push(node->left);
				if (node->right != nullptr) q.push(node->right);
			}
			ret.push_back(tmp);
		}
		return ret;
	}
};