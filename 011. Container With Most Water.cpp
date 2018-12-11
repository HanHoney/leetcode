//11. Container With Most Water

#include <iostream>
#include <vector>
using namespace std;
class Solution {   //����
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

	int maxArea1(vector<int>& height) {    //һ��ѭ����ÿ��ֻŲ���̰壨��������Ŀ��ܣ���Ų�����岻�����Ӹ߶ȣ��������ٿ�ȣ��޷��ҵ�����������
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

