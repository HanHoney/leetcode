//62. Unique Paths
//Medium   ans[m][n]=ans[m-1][n]+ans[m][n-1]
//TC:O(mn)   SC:O(max(m,n))  【未优化：O(mn)】
//保证 m < n

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m > n) swap(m, n);
		if (m < 2) return m;
		vector<int> res(n, 1);
		for (int i = 1; i < m; i++) {     //m<n循环更高效~
			for (int j = 1; j < n; j++) {
				res[j] += res[j - 1];
			}
		}
		return res[n - 1];
	}
};

/*****
int main() {
	int m, n;
	m = 7;
	n = 3;
	Solution s;
	cout << s.uniquePaths(m, n) << endl;
	system("pause");
}
*****/