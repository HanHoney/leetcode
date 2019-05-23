//907. Sum of Subarray Minimums
//Medium

//维护严格递增的stack
//和【84题】类似

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	//m[i][j]:minimum from A[i] to A[j]  O(n^2) TLE 卡常数

	//use stack: O(n) 维护递增序列。栈中前一个是left，被pop时遇到的是right。
	//left[i]:A[i]左边最后一个 小于 A[i]的值的下标
	//right[i]:A[i]右边第一个 小于等于 A[i]的值的下标
	//A[i]总共出现的次数:(i-left[i])*(right[i]-i)
	//A[i]is minimum in (left[i],right[i])
	//the counts A[i] used:(i-left[i])*(right[i]-i); 

	int sumSubarrayMins(vector<int>& A) {
		if (A.empty()) return 0;
		int ret = 0;
		int mod = 1e9 + 7;
		stack<int> s;
		int n = A.size();
		vector<int> left(n, -1);
		vector<int> right(n, n);
		for (int i = 0; i < n; ++i) {
			while (!s.empty() && A[i] <= A[s.top()]) {  
				right[s.top()] = i;
				s.pop();
			}
			if (!s.empty()) {
				left[i] = s.top();
			}
			s.push(i);
		}
		for (int i = 0; i < n; ++i) {
			ret = (ret + (i - left[i])*(right[i] - i) % mod*A[i] % mod) % mod;
		}
		return ret;
	}
};