//162. Find Peak Element
//Medium
//¶þ·Ö·¨

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		int mid = 0;
		while (l < r) {
			mid = (l + r) / 2;
			if (mid>0 && nums[mid]<nums[mid - 1]) {
				r = mid - 1;
			}
			else if (mid<nums.size() - 1 && nums[mid]<nums[mid + 1]) {
				l = mid + 1;
			}
			else {
				return mid;
			}
		}
		return l;
	}
};