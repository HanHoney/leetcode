//113. Path Sum II
//Medium
//DFS

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> ret;
		if (root == nullptr) return ret;
		vector<int> path;
		path.push_back(root->val);
		dfs(ret, path, root, sum - root->val);
		return ret;
	}
private:
	//note：权重可能为负数
	static void dfs(vector<vector<int>>& ret, vector<int>& path, TreeNode* root, int sum) {
		if (root->left == nullptr&&root->right == nullptr&&sum == 0) {
			ret.push_back(path);
			return;
		}
		if (root->left != nullptr) {
			path.push_back(root->left->val);
			dfs(ret, path, root->left, sum - root->left->val);
			path.pop_back();
		}
		if (root->right != nullptr) {
			path.push_back(root->right->val);
			dfs(ret, path, root->right, sum - root->right->val);
			path.pop_back();
		}
	}
};