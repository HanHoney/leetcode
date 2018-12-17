//124. Binary Tree Maximum Path Sum
//Hard
//递归

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	int maxPathSum(TreeNode* root) {
		int res = INT_MIN;
		maxPathSum(root, res);
		return res;
	}
private:
	//root结点之后的子路径的最大权重(单路)
	static int maxPathSum(TreeNode* root, int& res) {
		if (root == nullptr) return 0;
		int leftMax = max(maxPathSum(root->left, res), 0);
		int rightMax = max(maxPathSum(root->right, res), 0);
		res = max(res, leftMax + rightMax + root->val); //双路加根节点更新最大权重
		return max(leftMax, rightMax) + root->val;		//只返回单支的路径值
	}
};

int main() {
	TreeNode n0(10);
	TreeNode n1(9);
	TreeNode n2(20);
	TreeNode n3(15);
	TreeNode n4(7);
	TreeNode n5(9);
	n0.left = &n1;
	n0.right = &n2;
	n2.left = &n3;
	n2.right = &n4;
	n4.left = &n5;
	Solution s;
	cout << s.maxPathSum(&n0) << endl;
	system("pause");
	return 0;
}