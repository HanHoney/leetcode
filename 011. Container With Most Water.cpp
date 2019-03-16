//11. Container With Most Water
//Medium
//TC:O(N) SC:O(1)
//每次只挪动短板（有面积变大的可能）。挪动长板不会增加高度，反而减少宽度，无法找到更大的面积。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {   
public:
	
	int maxArea1(vector<int>& height) {    
		int ret = 0;
		int left = 0, right = height.size() - 1;
		while (left < right) {
			int curr = min(height[left], height[right])*(right - left);
			ret = max(ret, curr);
			if (height[left] < height[right]) {
				left++;
			}
			else right--;
		}
		return ret;
	}
};

