//84. Largest Rectangle in Histogram
//Hard

//和【907】题类似
//维护严格递增栈,O(n)
//left[i]记录i左边最后一个比他小的的
//right[i]记录i右边第一个不比他大的
//TC:O(n) SC:O(n)

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		if (heights.empty()) return 0;
		int ret = 0;
		stack<int> s;
		int n = heights.size();
		vector<int> left(n, -1);
		vector<int> right(n, n);
		for (int i = 0; i < n; ++i) {
			while (!s.empty() && heights[i] <= heights[s.top()]) {
				right[s.top()] = i;
				s.pop();
			}
			if (!s.empty()) {
				left[i] = s.top();
			}
			s.push(i);
		}
		for (int i = 0; i < n; ++i) {
			ret = max(ret, (right[i] - left[i] - 1)*heights[i]);
		}
		return ret;
}
};

#if 0
int main() {
	vector<int> h{ 2,1,5,6,2,3 };
	Solution s;
	cout << s.largestRectangleArea(h) << endl;
	system("pause");
	return 0;
}
#endif