//84. Largest Rectangle in Histogram
//Hard
/****************
方法①：
	对于每条直方图，分别向左右扫描，找到左右边界，计算以当前高度为宽的矩形。
		TC:O(n^2)
		SC:O(1)

方法②：
	借助stack做筛子，一次扫描得到以当前高度做宽的左右边界。维持一个高度非递减的stack，存高度对应的index。
		TC:O(n)
		SC:O(n)
	https://www.cnblogs.com/love-yh/p/7182920.html
****************/

 

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:

	//TC:O(n^2) 	SC:O(1)
	int largestRectangleArea1(vector<int>& heights) {
		int n = heights.size();
		int ret = 0;
		for (int i = 0; i < n; i++) {
			int left = 0, right = n - 1;
			for (int j = i; j >= 0; j--) {	//向左遍历，找到左界index
				if (heights[j] < heights[i]) {
					left = j + 1;
					break;
				}
			}
			for (int j = i; j < n; j++) {   //向右扫描，找到右界index
				if (heights[j] < heights[i]) {
					right = j - 1;
					break;
				}
			}
			int tmpArea = (right - left + 1)*heights[i];
			if (tmpArea > ret) ret = tmpArea;
		}
		return ret;
	}

	//TC:O(n)	 SC:O(n)
	//筛子，筛掉不符合短板特性的，使用stack
	int largestRectangleArea(vector<int>& heights) {
		int ret = 0;
		heights.push_back(0);	//保证最后有一个下降
		stack<int> s;
		for (int i = 0; i < heights.size();) {
			//维护栈中index对应元素非递减
			if (s.empty() || heights[i] >= heights[s.top()]) {
				s.push(i++);	//当栈为空，即所有直方图都计算完毕，将最后一个0入栈，同时i+1变为n，跳出循环
			}
			else {
				int tmp = s.top();
				s.pop();
				ret = max(ret, heights[tmp] * (s.empty() ? i : i - s.top() - 1));
			}
		}
		return ret;
	}
};

//
//int main() {
//	vector<int> h{ 2,1,5,6,2,3 };
//	Solution s;
//	cout << s.largestRectangleArea(h) << endl;
//	system("pause");
//	return 0;
//}