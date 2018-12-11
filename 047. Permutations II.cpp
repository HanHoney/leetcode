//47. Permutations II
//Medium
//same as P46

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.empty()) return ret;
		sort(nums.begin(), nums.end());
		do {
			ret.push_back(nums);
		} while (nextPermutation(nums));
		return ret;
	}
private:
	bool nextPermutation(vector<int>& curr) {
		for (int i = curr.size() - 2; i >= 0; i--) {
			if (curr[i] < curr[i + 1]) {
				for (int j = curr.size() - 1; j > i; j--) {
					if (curr[j] > curr[i]) {
						swap(curr[i], curr[j]);
						sort(curr.begin() + i + 1, curr.end());
						return true;
					}
				}
			}
		}
		return false;
	}
};

/*
int main() {
	Solution s;
	vector<int> vec{ 1,1,2 };
	for (auto v : s.permuteUnique(vec)) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
	}
	system("pause");
}
*/