//69. Sqrt(x)
//Easy
//二分查找，轮子题~

class Solution {
public:
	int mySqrt(int x) {
		if (x < 0) return -1;
		if (x == 0 || x == 1) return x;
		int l = 0, r = x;
		int ret = 0;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (m <= x / m) {
				l = m + 1;
				ret = m;
			}
			else {
				r = m - 1;
			}
		}
		return ret;
	}
};