//581. Shortest Unsorted Continuous Subarray
//Easy

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

class Solution {
public:

	//最优解
	//TC:O(N)	SC:O(1)
	int findUnsortedSubarray(vector<int>& nums) {
		if (nums.size()<2) return 0;
		int left = nums.size();
		int right = -1;
		int nmax = INT_MIN, nmin = INT_MAX;
		for (int i = 0; i<nums.size(); i++) {
			nmax = max(nmax, nums[i]);
			if (nums[i] < nmax) {
				right = i;
			}
		}
		for (int i = nums.size() - 1; i >= 0; i--) {
			nmin = min(nmin, nums[i]);
			if (nums[i]>nmin) {
				left = i;
			}
		}
		return max(0, right - left + 1);
	}

	//TC:O(NlogN) SC:O(N)
	//使用sort()和拷贝数组
};

/*
test case:
1 5 4 3 2 6 7
*/
