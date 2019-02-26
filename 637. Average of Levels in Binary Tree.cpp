//637. Average of Levels in Binary Tree
//Easy

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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> ret;
		if (root == nullptr) return ret;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int n = q.size();
			double sum = 0;
			for (int i = 0; i < n; i++) {
				TreeNode *curr = q.front();
				sum += curr->val;
				q.pop();
				if (curr->left) q.push(curr->left);
				if (curr->right) q.push(curr->right);
			}
			ret.push_back(sum / n);
		}
		return ret;
	}
};