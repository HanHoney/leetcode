//739. Daily Temperatures
//Medium

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> ret(T.size(), 0);
		stack<int> s;
		for (int i = 0; i < T.size(); ++i) {
			while (!s.empty() && T[s.top()] < T[i]) {
				ret[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}
		return ret;
	}
};

