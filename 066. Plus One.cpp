//66. Plus One
//Easy

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		if (digits.empty()) return digits;
		for (int i = digits.size() - 1; i >= 0; i--) {
			digits[i]++;
			if (digits[i] < 10) break;  //一旦没有进位，跳出循环
			else digits[i] = 0;
		}
		if (digits[0] == 0) digits.insert(digits.begin(), 1);
		return digits;
	}
};