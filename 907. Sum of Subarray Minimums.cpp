//907. Sum of Subarray Minimums
//Medium

//ά���ϸ������stack
//�͡�84�⡿����

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
	//m[i][j]:minimum from A[i] to A[j]  O(n^2) TLE ������

	//use stack: O(n) ά���������С�ջ��ǰһ����left����popʱ��������right��
	//left[i]:A[i]������һ�� С�� A[i]��ֵ���±�
	//right[i]:A[i]�ұߵ�һ�� С�ڵ��� A[i]��ֵ���±�
	//A[i]�ܹ����ֵĴ���:(i-left[i])*(right[i]-i)
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