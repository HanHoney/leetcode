//238. Product of Array Except Self
//Medium
//DP
//A[i]����a(0)��a(i-1)�ĳ˻� B[i]����a(i+1)��a(n-1)�ĳ˻� A[0]=B[n-1]=1
//��res[i]=A[i]*B[i]

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ret(nums.size());
		ret[0] = 1;
		for (int i = 1; i<nums.size(); i++) {
			ret[i] = ret[i - 1] * nums[i - 1];
		}
		int tmp = 1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			tmp *= nums[i + 1];
			ret[i] *= tmp;
		}
		return ret;
	}
};