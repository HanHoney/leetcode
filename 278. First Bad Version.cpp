//278. First Bad Version
//Easy

#include <iostream>
using namespace std;
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int left = 1, right = n;
		while (left < right) {
			int mid = left + (right - left) / 2;    //(left+right)/2 »áÒç³ö
			if (isBadVersion(mid)) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};