// 1. Two Sum
// Easy

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:

	//双指针+sort
	//TC:O(nlogn)	SC:O(n)
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> tmp = nums;
		sort(tmp.begin(),tmp.end());
		int len = tmp.size();
		int left, right;
		left = 0;
		right = len - 1;
		while (left < right) {
			if (tmp[left] + tmp[right] < target) {
				left++;
			}
			else if (tmp[left] + tmp[right] > target) {
				right--;
			}
			else break;
		}
		vector<int> ret;
		for (int i = 0; i < len; i++) {
			if (nums[i] == tmp[left] || nums[i] == tmp[right]) {      //保证每个索引只使用一次
				ret.push_back(i);
			}
			if (ret.size() == 2) {
				break;
			}
		}   //for循环直接保证索引顺序
		return ret;
	}

	//哈希表
	//TC:O(n)	SC:O(n)
	vector<int> twoSum1(vector<int>& nums, int target) {
		unordered_map<int, int> map;	//存(val,idx)
		vector<int> ret;
		for (int i = 0; i < nums.size(); i++) {
			map[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) {
			int toFind = target - nums[i];
			auto it = map.find(toFind);
			if (it != map.end() && it->second > i) {
				ret.push_back(i);
				ret.push_back(it->second);
				return ret;
			}
		}
		return ret;
	}
};


int main() {
	vector<int> numbers = {2,11,7,15};
	int tar = 18;
	Solution s = Solution();
	vector<int> res;
	res = s.twoSum1(numbers, tar);
	cout << res[0] << " " << res[1] << endl;
	system("pause");
	return 0;
}
