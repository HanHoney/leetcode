//18.4Sum
//¼Ð±Æ O(n^3) 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		if (nums.size() < 4) return result;
		sort(nums.begin(), nums.end());
		if (nums.front() > 0 || nums.back() < 0) return result;
		for (int i = 0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;   //×¢ÒâÂß¼­£¬ÊÇif
			int a = nums[i];
			for (int j = i + 1; j < nums.size() - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int b = nums[j];
				int low = j + 1;
				int high = nums.size() - 1;
				while (low < high) {
					int c = nums[low];
					int d = nums[high];
					if (a + b + c + d == target) {
						result.push_back({ a,b,c,d });
						while (low < nums.size() - 1 && nums[low + 1] == nums[low]) low++;
						while (high > j + 1 && nums[high - 1] == nums[high]) high--;
						low++;
						high--;
					}
					else if (a + b + c + d > target) {
						while (high > j + 1 && nums[high - 1] == nums[high]) high--;
						high--;
					}
					else {
						while (low < nums.size() - 1 && nums[low + 1] == nums[low]) low++;
						low++;
					}
				}
			}
		}
		return result;
	}
};

/*************************
int main() {
	Solution s;
	vector<int> v = { 1, 0, -1, 0, 2, -2 };
	int t = 0;
	vector<vector<int>> res;
	res = s.fourSum(v, t);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < 4; j++) {
			cout << res.at(i).at(j)<<" ";
		}
		cout << endl;
	}
	system("pause"); 
}
**************************/