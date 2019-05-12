//275. H-Index II
//Medium
//Binary Search

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty()) return 0;
		int n = citations.size();
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (n - mid == citations[mid]) {
				return citations[mid];
			}
			else if (n - mid > citations[mid]) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return n - left;
	}
};
