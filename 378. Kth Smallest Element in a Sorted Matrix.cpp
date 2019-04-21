
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		if (k == 1) return matrix[0][0];
		int n = matrix.size();
		if (k == n * n) return matrix[n - 1][n - 1];
		priority_queue<int> pq;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((i + 1)*(j + 1) > k) break;
				if (pq.size() == k) {
					if (matrix[i][j] < pq.top()) {
						pq.pop();
						pq.push(matrix[i][j]);
					}
				}
				else pq.push(matrix[i][j]);
			}
		}
		return pq.top();
	}
};