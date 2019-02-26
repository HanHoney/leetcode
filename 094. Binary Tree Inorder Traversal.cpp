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
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
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
		if (root == nullptr) return;
		inorderTraversal(root->left, ret);
		ret.push_back(root->val);
		inorderTraversal(root->right, ret);
	}

	//② 非递归
	//一路向左，左无转右
	//Morris中序遍历
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root) return ret;
		stack<TreeNode*> s;
		TreeNode *curr = root;
		while (!s.empty() || curr != nullptr) {		//①没有分支可走 ②这个分支走到了头
			if (curr) {
				s.push(curr);
				curr = curr->left;
			}
			else {
				curr = s.top();
				ret.push_back(curr->val);
				s.pop();
				curr = curr->right;
			}
		}
		return ret;
	}
};

#if 0
int main() {
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);

	t1.left = &t2;
	t1.right = &t3;
	t3.left = &t4;
	t4.right = &t5;

	Solution s;

	for (auto a : s.inorderTraversal(&t1)) {
		cout << a << " ";
	}
	cout << endl;
	//2 1 4 5 3

	system("pause");
	return 0;
}
#endif