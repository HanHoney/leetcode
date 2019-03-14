//297. Serialize and Deserialize Binary Tree
//Hard
//序列化和反序列化二叉树 剑指offer
//使用先序遍历

#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == nullptr) return "#";
		return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		return deserializeHelper(data);
	}

private:
	TreeNode * deserializeHelper(string& str) {
		if (str[0] == '#') {
			if (str.size() > 1) str = str.substr(2);	//默认从开始位置到尾
			return nullptr;
		}
		int pos = str.find_first_of(',');
		TreeNode* ret = new TreeNode(stoi(str.substr(0, pos)));
		str = str.substr(pos + 1);
		ret->left = deserializeHelper(str);
		ret->right = deserializeHelper(str);
		return ret;
	}
};