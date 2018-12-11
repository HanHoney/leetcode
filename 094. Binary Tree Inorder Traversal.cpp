//94. Binary Tree Inorder Traversal (中序遍历)
//Medium
//左 中 右
//①递归 ②非递归

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	//① 递归
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		inorderTraversal(root, ret);
		return ret;
	}
	void inorderTraversal(TreeNode* root, vector<int> &ret) {
		if (root == NULL) return;
		inorderTraversal(root->left, ret);
		ret.push_back(root->val);
		inorderTraversal(root->right, ret);
	}

	//② 非递归
	//一直向左走，左支无路可走再走右支
	vector<int> inorderTraversal1(TreeNode* root) {
		vector<int> ret;
		if (!root) return ret;
		stack<TreeNode*> st;
		while (!st.empty() || root) {   //①没有分支可走 ②这个分支走到了头
			if (root) {
				st.push(root);
				root = root->left;
			}
			else {
				root = st.top();
				ret.push_back(root->val);
				st.pop();
				root = root->right;
			}
		}
		return ret;
	}
};

//
//int main() {
//	TreeNode t1(1);
//	TreeNode t2(2);
//	TreeNode t3(3);
//	TreeNode t4(4);
//	TreeNode t5(5);
//
//	t1.left = &t2;
//	t1.right = &t3;
//	t3.left = &t4;
//	t4.right = &t5;
//
//	Solution s;
//
//	for (auto a : s.inorderTraversal(&t1)) {
//		cout << a << " ";
//	}
//	cout << endl;
//	//2 1 4 5 3
//
//	system("pause");
//	return 0;
//}
