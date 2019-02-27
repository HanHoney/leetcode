//662. Maximum Width of Binary Tree
//Medium
//queue中放每一层的节点和位置
//当前层只有一个节点时，改写idx为0，防止idx溢出.

#include <iostream>
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
	int widthOfBinaryTree(TreeNode* root) {
		if (root == nullptr) return 0;
		queue<pair<TreeNode*, int>> q;
		q.push({ root,0 });
		int res = 0;
		while (!q.empty()) {
			int n = q.size();
			if (n == 1) {
				q.push({ q.front().first,0 });
				q.pop();
			}
			res = max(res, q.back().second - q.front().second + 1);
			for (int i = 0; i < n; i++) {
				TreeNode *curr = q.front().first;
				int idx = q.front().second;
				q.pop();
				if (curr->left) {
					q.push({ curr->left,2 * idx });
				}
				if (curr->right) {
					q.push({ curr->right,2 * idx + 1 });
				}
			}
		}
		return res;
	}
};