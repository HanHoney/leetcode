//260. Single Number III
//Medium
//���

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int tmp = 0;
		for (auto num : nums) {
			tmp ^= num;
		}
		int a = 0x1;
		while ((tmp&a) == 0) {   //ע�����ȼ���������
			a = a << 1;
		}
		vector<int> res({ 0,0 });
		for (auto num : nums) {
			if (num&a) {
				res[0] ^= num;
			}
			else {
				res[1] ^= num;
			}
		}
		return res;
	}
};