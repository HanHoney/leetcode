//104. Maximum Depth of Binary Tree
//Easy
//¼òµ¥µÝ¹é

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode *root) {
		if (root == NULL) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};
//
//int main() {
//	TreeNode t1(1);
//	TreeNode t2(2);
//	TreeNode t3(3);
//	TreeNode t4(4);
//	TreeNode t5(5);
//	TreeNode t6(6);
//	TreeNode t7(7);
//	TreeNode t8(8);
//	TreeNode t9(9);
//
//	t1.left = &t2;
//	t1.right = &t3;
//	t2.left = &t4;
//	t2.right = &t5;
//	t3.right = &t6;
//	t4.left = &t7;
//	t4.right = &t8;
//	t8.left = &t9;
//
//	Solution s;
//	cout << s.maxDepth(&t1) << endl;
//	system("pause");
//	return 0;
//}