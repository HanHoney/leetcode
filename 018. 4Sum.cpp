//18.4Sum
//夹逼 O(n^3) 

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ret;
		if (nums.size() < 4) return ret;
		sort(nums.begin(), nums.end());
		if (4 * nums.front() > target || 4 * nums.back() < target) return ret;
		for (int i = 0; i < nums.size() - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int a = nums[i];
			for (int j = i + 1; j < nums.size() - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int b = nums[j];
				int k = j + 1;
				int l = nums.size() - 1;
				while (k < l) {
					int c = nums[k];
					int d = nums[l];
					int sum = a + b + c + d;
					if (sum == target) {
						ret.push_back({ a,b,c,d });
						k++;
						l--;
						while (nums[k] == nums[k - 1] && k < l) k++;
						while (nums[l] == nums[l + 1] && k < l) l--;
					}
					else if (sum<target) {
						k++;
						while (nums[k] == nums[k - 1] && k < l) k++;
					}
					else {
						l--;
						while (nums[l] == nums[l + 1] && k < l) l--;
					}
				}
			}
		}
		return ret;
	}

	//借助哈希表缓存
	vector<vector<int>> fourSum_HashMap(vector<int>& nums, int target) {
		vector<vector<int>> ret;
		if (nums.size()<4) return ret;
		sort(nums.begin(), nums.end());
		if (nums.front() * 4>target || nums.back() * 4<target) return ret;
		unordered_map<int, vector<pair<int, int>>> map;
		for (int i = 0; i<nums.size(); i++) {
			for (int j = i + 1; j<nums.size(); j++) {
				map[nums[i] + nums[j]].push_back(make_pair(i, j));
			}
		}
		for (int i = 0; i<nums.size(); i++) {     //这两个数是a,b 表中存的是c,d
			if (i>0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j<nums.size(); j++) {
				if (j>i + 1 && nums[j] == nums[j - 1]) continue;
				int key = target - nums[i] - nums[j];
				if (map.find(key) == map.end()) {
					continue;
				}
				auto tmp = map[key];
				for (int k = 0; k<tmp.size(); k++) {
					if (j<tmp[k].first) {
						vector<int> v = { nums[i],nums[j],nums[tmp[k].first],nums[tmp[k].second] };
						if (!ret.empty() && v[0] == ret.back()[0] && v[1] == ret.back()[1] && v[2] == ret.back()[2] && v[3] == ret.back()[3]) continue;
						ret.push_back(v);
					}
				}
			}
		}
		return ret;
	}
};

#if 0
int main() {
	Solution s;
	vector<int> v = { 1, 0, -1, 0, 2, -2 };
	int t = 0;
	vector<vector<int>> res;
	res = s.fourSum(v, t);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < 4; j++) {
			cout << res[i][j]<<" ";
		}
		cout << endl;
	}
	system("pause"); 
	return 0;
}
#endif