//334. Increasing Triplet Subsequence
//Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int min1 = INT_MAX, min2 = INT_MAX;
		for (int num : nums) {
			if (num < min1) min1 = num;
			else if (num > min1&&num < min2) min2 = num;
			else if (num > min2) return true;
		}
		return false;
	}
};

#if 0
int main() {
	vector<int> v1 = { 1,1,2,-5 };
	vector<int> v2 = { 2,5,3,1,4 };
	vector<int> v3 = { 1,2,3,4,5 };
	vector<int> v4 = { 5,4,3,2,1 };
	Solution s;
	cout << s.increasingTriplet(v1) << endl;
	cout << s.increasingTriplet(v2) << endl;
	cout << s.increasingTriplet(v3) << endl;
	cout << s.increasingTriplet(v4) << endl;
	system("pause");
	return 0;
}
#endif