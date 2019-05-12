//47. Permutations II
//Medium
//same as P46

#include <iostream>
#include <vector>
#include <set>
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

class Solution_1 {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) { 
		vector<vector<int>> ret;
		if (nums.empty()) return ret;
		sort(nums.begin(), nums.end());
		vector<int> path;
		vector<bool> visited(nums.size());
		dfs(ret, path, nums, visited);
		return ret;
	}
	void dfs(vector<vector<int>>& ret, vector<int>& path, vector<int> nums, vector<bool>& visited) {
		if (path.size() == nums.size()) {
			ret.push_back(path);
			return;
		}
		int lastVisited = INT_MIN;
		for (int i = 0; i < nums.size(); ++i) {
			if (!visited[i] && nums[i] != lastVisited) {
				visited[i] = true;
				path.emplace_back(nums[i]);
				dfs(ret, path, nums, visited);
				lastVisited = nums[i];
				visited[i] = false;
				path.pop_back();
			}
		}
	}
};

class Solution_Set {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.empty()) return ret;
		sort(nums.begin(), nums.end());
		set<vector<int>> mySet;
		dfs(mySet, nums, 0);
		for (auto v : mySet) {
			ret.push_back(v);
		}
		return ret;
	}
	void dfs(set<vector<int>>& mySet, vector<int>& nums, int index) {
		if (index == nums.size()) {
			mySet.insert(nums);
			return;
		}
		for (int i = index; i < nums.size(); ++i) {
			swap(nums[i], nums[index]);
			dfs(mySet, nums, index + 1);
			swap(nums[i], nums[index]);
		}
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