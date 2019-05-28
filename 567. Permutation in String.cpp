//567. Permutation in String
//Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() > s2.size()) return false;
		vector<int> nums1(26, 0);
		vector<int> nums2(26, 0);
		for (int i = 0; i < s1.size(); ++i) {
			++nums1[s1[i] - 'a'];
			++nums2[s2[i] - 'a'];
		}
		for (int i = s1.size(); i < s2.size(); ++i) {
			if (nums1 == nums2) return true;
			--nums2[s2[i - s1.size()] - 'a'];
			++nums2[s2[i] - 'a'];
		}
		return nums1 == nums2;
	}
};