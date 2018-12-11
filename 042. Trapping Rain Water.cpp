//42. Trapping Rain Water
//Hard
//同类题：P11

#include <vector>
using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (n < 3) return 0;
		int left = 0, right = n - 1;
		int res = 0;
		int l1, l2;
		l1 = height[left];
		l2 = height[right];
		while (left < right) {
			if (l1 < l2) {  //移动短板
				left++;
				if (height[left] > l1) l1 = height[left];
				else res += l1 - height[left];
			}
			else {
				right--;
				if (height[right] > l2) l2 = height[right];
				else res += l2 - height[right];
			}
		}
		return res;
	}
};