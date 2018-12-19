//114. Flatten Binary Tree to Linked List
//Medium
//in-place
//按照先序遍历串联即可

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		if (!root) return;
		flatten(root->left);
		TreeNode *tmp = getRightLeafNode(root->left);
		flatten(root->right);
		if (tmp == nullptr) return;
		tmp->right = root->right;
		root->right = root->left;
		root->left = nullptr;
		return;
	}

	void flatten1(TreeNode* root) {
		if (!root) return;
		TreeNode *curr = root;
		while (curr) {
			if (curr->left) {
				TreeNode *prev = curr->left;
				while (prev->right) {
					prev = prev->right;
				}
				prev->right = curr->right;
				curr->right = curr->left;
				curr->left = nullptr;
			}
			curr = curr->right;
		}
	}
private:
	static TreeNode* getRightLeafNode(TreeNode* root) {
		if (!root) return nullptr;
		while (root->right) {
			root = root->right;
		}
		return root;
	}
};

int main() {
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	n1.left = &n2;
	n1.right = &n5;
	n2.left = &n3;
	n2.right = &n4;
	n5.right = &n6;
	Solution s;
	s.flatten(&n1);
	for (TreeNode *p = &n1; p; p = p->right) {
		cout << p->val << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}