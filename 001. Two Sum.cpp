// 1. Two Sum
// Easy

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:

#if 0
	//双指针+sort
	//TC:O(nlogn)	SC:O(n)
	vector<int> twoSum_1(vector<int>& nums, int target) {
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
#endif

	//哈希表
	//TC:O(n)	SC:O(n)
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		unordered_map<int, int> umap;		//(val,index)
		for (int i = 0; i < nums.size(); ++i) {
			if (umap.find(target - nums[i]) != umap.end()) {
				ret.emplace_back(umap[target - nums[i]]);
				ret.emplace_back(i);
				break;
			}
			umap[nums[i]] = i;
		}
		return ret;
	}
};

#if 0
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
#endif