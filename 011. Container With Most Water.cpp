//11. Container With Most Water

#include <iostream>
#include <vector>
using namespace std;
class Solution {   //暴力
public:
	int maxArea(vector<int>& height) {
		int ret = 0;
		int size = height.size();
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				int h = height[i] < height[j] ? height[i] : height[j];
				int tmp = h * (j - i);
				ret = tmp > ret ? tmp : ret;
			}
		}
		return ret;
	}

	int maxArea1(vector<int>& height) {    //一次循环，每次只挪动短板（有面积变大的可能）。挪动长板不会增加高度，反而减少宽度，无法找到更大的面积。
		int ret = 0;
		int left = 0, right = height.size() - 1;
		while (right > left) {
			int cmp = height[right] - height[left];
			int tmp = (cmp < 0 ? height[right] : height[left])*(right - left);
			ret = tmp > ret ? tmp : ret;
			if (cmp < 0) {
				right--;
			}
			else left++;
		}
		return ret;
	}
};

