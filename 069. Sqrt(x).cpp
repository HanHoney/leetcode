//69. Sqrt(x)
//Easy
//���ֲ��ң�������~

class Solution {
public:
	int mySqrt(int x) {
		if (x < 0) return -1;   //�Ƿ�����
		if (x == 0) return 0;
		int l = 1, r = x;
		int ret = 0;
		while (l <= r) {
			int m = (l + r) >> 1;   
		 // int m = (l + r) / 2; 
			if (m <= x / m) {
				l = m + 1;
				ret = m;
			}
			else r = m - 1;
		}
		return ret;
	}
};