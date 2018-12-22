//59. Spiral Matrix II
//Medium
//模拟

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> ret(n, vector<int>(n));
		int num = 1;
		int begin = 0, end = n - 1;
		while(begin < end) {
			for (int col = begin; col < end; col++) {
				ret[begin][col] = num++;
			}
			for (int row = begin; row < end; row++) {
				ret[row][end] = num++;
			}
			for (int col = end; col > begin; col--) {
				ret[end][col] = num++;
			}
			for (int row = end; row > begin; row--) {
				ret[row][begin] = num++;
			}
			begin++;
			end--;
		}
		if (begin == end) {
			ret[begin][begin] = num;
		}
		return ret;
	}
};

int main() {
	int n;
	while (cin >> n) {
		Solution s;
		vector<vector<int>> ret = s.generateMatrix(n);
		for (auto &v : ret) {
			for (auto num : v) {
				cout << num << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
