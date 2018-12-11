//88. Merge Sorted Array
//Easy

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {    //nums1大小为m+n，后面n个是0
		for (int k = m + n - 1, i = m - 1, j = n - 1; k >= 0; k--) {
			if (i >= 0 && j >= 0) {
				nums1[k] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
			}
			else if (j >= 0) {
				nums1[k] = nums2[j--];
			}
		}
	}
};

//
//int main() {
//	vector<int> nums1{ 1,2,3,0,0,0 };
//	vector<int> nums2{ 2,5,6 };
//	Solution s;
//	s.merge(nums1, 3, nums2, 3);
//	for (auto n : nums1) {
//		cout << n << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}