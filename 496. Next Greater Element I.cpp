//496. Next Greater Element I
//Easy

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> umap;
		stack<int> stk;
		//ÑÏ¸ñµÝ¼õÕ»
		for (int num : nums2) {
			while (!stk.empty() && num > stk.top()) {
				umap[stk.top()] = num;
				stk.pop();
			}
			stk.push(num);
		}
		vector<int> ret(nums1.size(), -1);
		for (int i = 0; i < nums1.size(); ++i) {
			if (umap.find(nums1[i]) != umap.end()) {
				ret[i] = umap[nums1[i]];
			}
		}
		return ret;
	}
};