//497. Random Point in Non-overlapping Rectangles
//Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	int sum;
	vector<vector<int>> rectangles;
	vector<int> counts;

public:

	Solution(vector<vector<int>> rects) {  //面积在构造函数中计算，否则每次pick()重复计算。
		rectangles = rects;
		sum = 0;  //所有矩形内的点数总和,not more than 2001*2001*100
		for (auto rectangle : rectangles) {
			sum += (rectangle[2] - rectangle[0] + 1)*(rectangle[3] - rectangle[1] + 1);
			counts.push_back(sum);
		}
	}

	vector<int> pick() {
		vector<int> ret(2);
		int index = -1;
		int n = rand() % sum + 1;
		for (int i = 0; i<counts.size(); ++i) {
			if (n <= counts[i]) {
				index = i;
				break;
			}
		}
		int x1 = rectangles[index][0];
		int y1 = rectangles[index][1];
		int x2 = rectangles[index][2];
		int y2 = rectangles[index][3];
		ret[0] = rand() % (x2 - x1 + 1) + x1;
		ret[1] = rand() % (y2 - y1 + 1) + y1;
		return ret;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(rects);
* vector<int> param_1 = obj->pick();
*/