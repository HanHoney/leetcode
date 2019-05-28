//85. Maximal Rectangle
//Hard
//①DP	②利用84题

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:

	//①DP 
	//TC:O(n^2)	SC:O(n)
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		const int m = matrix.size();
		const int n = matrix[0].size();
		vector<int> left(n, 0);			//左边界
		vector<int> right(n, n);		//右边界
		vector<int> height(n, 0);		//高度
		int ret = 0;
		for (int i = 0; i < m; i++) {
			int l = 0, r = n;
			for (int j = 0; j < n; j++) {		//从左向右遍历
				if (matrix[i][j] == '1') {
					height[j]++;
					left[j] = max(left[j], l);
				}
				else {
					height[j] = 0;
					left[j] = 0;
					l = j + 1;
				}
			}
			for (int j = n - 1; j >= 0; j--) {
				if (matrix[i][j] == '1') {
					right[j] = min(right[j], r);
					ret = max(ret, height[j] * (right[j] - left[j]));
				}
				else {
					right[j] = n;
					r = j;
				}
			}
		}
		return ret;
	}

	//②利用84题结果
	//Runtime: 16 ms, faster than 66.21% of C++ online submissions for Maximal Rectangle.
	int largestRectangleArea(vector<int>& heights) {
		int maxArea = 0;
		heights.push_back(0);
		stack<int> s;
		for (int i = 0; i < heights.size();) {
			if (s.empty() || heights[i] >= heights[s.top()]) {
				s.push(i++);
			}
			else {
				int tmp = s.top();
				s.pop();
				maxArea = max(maxArea, heights[tmp] * (s.empty() ? i : i - s.top() - 1));
			}
		}
		return maxArea;
	}
	int maximalRectangle1(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int ret = 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> heights(n, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == '1') heights[j]++;
				else heights[j] = 0;
			}
			ret = max(ret, largestRectangleArea(heights));
		}
		return ret;
	}

};
//
//int main() {
//	vector<vector<char>> m{ {'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'} };
//	Solution s;
//	cout << s.maximalRectangle(m) << endl;
//	cout << s.maximalRectangle1(m) << endl;
//	system("pause");
//	return 0;
//}
