//4. Median of Two Sorted Arrays
//Hard
//O(log(m+n))
//二分查找，复用findKth()
//Iterator相当于指针？？

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		const int total = m + n;
		if (total % 2)
			return findKth(nums1.begin(), nums2.begin(), m, n, total / 2 + 1);
		else
			return (findKth(nums1.begin(), nums2.begin(), m, n, total / 2) + findKth(nums1.begin(), nums2.begin(), m, n, total / 2 + 1)) / 2.0;
	}
private:
	//static int findKth(vector<int>::iterator A, vector<int>::iterator B, int m, int n, int k) {   //保证m≤n
	//	if (m > n) return findKth(B, A, n, m, k);
	//	if (m == 0) return B[k - 1];
	//	if (k == 1) return min(A[0], B[0]);
	//	int i = min(k / 2, m), j = k - i;
	//	if (A[i - 1] == B[j - 1]) {
	//		return A[i - 1];
	//	}
	//	else if (A[i - 1] > B[j - 1]) {
	//		return findKth(A, B + j, m, n - j, k - j);
	//	}
	//	else if (A[i - 1] < B[j - 1]) {
	//		return findKth(A + i, B, m - i, n, k - i);
	//	}
	//}
	int findKth(vector<int>::iterator A, vector<int>::iterator B, int m, int n, int k) {
		if (m>n) return findKth(B, A, n, m, k);
		if (m == 0) return *(B + k - 1);
		if (k == 1) return min(*A, *B);

		int i = min(k / 2, m), j = k - i;
		if (*(A + i - 1) == *(B + j - 1)) return *(A + i - 1);
		else if (*(A + i - 1)>*(B + j - 1)) return findKth(A, B + j, m, n - j, k - j);
		else return findKth(A + i, B, m - i, n, k - i);
	}
};          

//int main() {
//	Solution test = Solution();
//	vector<int> t1, t2;
//	t1 = { };
//	t2 = { 4 };
//	cout << test.findMedianSortedArrays(t1, t2) << endl;
//	system("pause");
//}