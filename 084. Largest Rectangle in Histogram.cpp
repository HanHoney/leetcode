//84. Largest Rectangle in Histogram
//Hard
/****************
�����٣�
	����ÿ��ֱ��ͼ���ֱ�������ɨ�裬�ҵ����ұ߽磬�����Ե�ǰ�߶�Ϊ��ľ��Ρ�
		TC:O(n^2)
		SC:O(1)

�����ڣ�
	����stack��ɸ�ӣ�һ��ɨ��õ��Ե�ǰ�߶���������ұ߽硣ά��һ���߶ȷǵݼ���stack����߶ȶ�Ӧ��index��
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
			for (int j = i; j >= 0; j--) {	//����������ҵ����index
				if (heights[j] < heights[i]) {
					left = j + 1;
					break;
				}
			}
			for (int j = i; j < n; j++) {   //����ɨ�裬�ҵ��ҽ�index
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
	//ɸ�ӣ�ɸ�������϶̰����Եģ�ʹ��stack
	int largestRectangleArea(vector<int>& heights) {
		int ret = 0;
		heights.push_back(0);	//��֤�����һ���½�
		stack<int> s;
		for (int i = 0; i < heights.size();) {
			//ά��ջ��index��ӦԪ�طǵݼ�
			if (s.empty() || heights[i] >= heights[s.top()]) {
				s.push(i++);	//��ջΪ�գ�������ֱ��ͼ��������ϣ������һ��0��ջ��ͬʱi+1��Ϊn������ѭ��
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