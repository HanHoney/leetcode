//108. Convert Sorted Array to Binary Search Tree
//Easy
//���ַ�
//TC:O(n)	SC:O(logn)

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
	TreeNode * sortedArrayToBST(vector<int>& nums) {
		if (nums.empty()) return nullptr;
		return sortedArrayToBST(nums, 0, nums.size());
	}
	TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r) {
		if (l >= r) return nullptr;
		int mid = (l + r - 1) / 2;  //��������
		//int mid = (l + r) / 2;    //��������
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBST(nums, l, mid);
		root->right = sortedArrayToBST(nums, mid + 1, r);
		return root;
	}
};