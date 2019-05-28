//503. Next Greater Element II
//Medium

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> ret(n, -1);
		stack<int> stk;
		for (int i = 0; i < 2 * n; ++i) {
			while (!stk.empty() && nums[i%n] > nums[stk.top() % n]) {
				if (stk.top() < n) ret[stk.top()] = nums[i%n];
				stk.pop();
			}
			stk.push(i);
		}
		return ret;
	}
};