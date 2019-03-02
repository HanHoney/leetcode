//179. Largest Number
//Medium

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string ret("");
		if (nums.empty()) return ret;
		sort(nums.begin(), nums.end(), cmp);
		for (int num : nums) {
			ret += to_string(num);
		}
		if (ret[0] == '0') {	//testcase: [0,0]->"0"
			ret = "0";
		}		
		return ret;
	}
	static bool cmp(const int& a, const int& b) {
		string s1 = to_string(a);
		string s2 = to_string(b);
		return s1 + s2 > s2 + s1;
	}
};