//120. Triangle
//Medium

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	//TC:O(n^2)	SC:O(n^2)
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		int ret = INT_MAX;
		int n = triangle.size();
		vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < n; i++) {
			dp[i][0] = dp[i - 1][0] + triangle[i][0];
			for (int j = 1; j < triangle[i].size(); j++) {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			ret = min(ret, dp[n - 1][i]);
		}
		return ret;
	}
	
	//TC:O(n^2)	SC:O(n)
	int minimumTotal1(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		int n = triangle.size();
		int ret = INT_MAX;
		vector<int> dp(n, INT_MAX);
		dp[0] = triangle[0][0];
		for (int i = 1; i < n; i++) {
			for (int j = triangle[i].size() - 1; j > 0; j--) {		//update from right
				dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
			}
			dp[0] += triangle[i][0];
		}
		for (int i = 0; i < n; i++) {
			ret = min(ret, dp[i]);
		}
		return ret;
	}

	//TC:O(n^2)	SC:O(1)
	int minimumTotal2(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		for (int i = triangle.size() - 2; i >= 0; i--) {
			for (int j = 0; j < triangle[i].size(); j++) {
				triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
			}
		}
		return triangle[0][0];
	}
};

int main() {
	vector<vector<int>> tr{ {2},{3,4},{6,5,7},{4,1,8,3} };
	Solution s;
	cout << s.minimumTotal(tr) << endl;
	cout << s.minimumTotal1(tr) << endl;
	cout << s.minimumTotal2(tr) << endl;
	system("pause");
	return 0;
}