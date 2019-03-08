//412. Fizz Buzz
//Easy

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string> strs(n, "");
		for (int i = 1; i <= n; i++) {
			if (i % 3 == 0) {
				strs[i - 1] += "Fizz";
			}
			if (i % 5 == 0) {
				strs[i - 1] += "Buzz";
			}
			if (i % 3 != 0 && i % 5 != 0) {
				strs[i - 1] += to_string(i);
			}
		}
		return strs;
	}
};