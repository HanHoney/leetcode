//15. 3Sum

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;
		if (nums.size() < 3)
			return ret;
		sort(nums.begin(), nums.end());             //将复杂度降至O(n^2)
		if (nums.front() > 0 || nums.back() < 0)    //所有元素同号，没有符合要求的三元组
			return ret;
		int n = nums.size();
		for (int i = 0; i < n - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1])    //相同的元素，只需要使用第一个
				continue;
			int a = nums[i];
			int low = i + 1;
			int high = n - 1;
			while (low < high) {
				int b = nums[low];
				int c = nums[high];
				if (a + b + c == 0) {
					vector<int> v;
					v.push_back(a);
					v.push_back(b);
					v.push_back(c);
					ret.push_back(v);
					while (low < n - 1 && nums[low + 1] == nums[low]) {    //跳过相同的元素
						low++;
					}
					while (high > i + 1 && nums[high - 1] == nums[high]) {
						high--;
					}
					low++;
					high--;
				}
				else if (a + b + c > 0) {
					while (high > i + 1 && nums[high - 1] == nums[high]) {
						high--;
					}
					high--;
				}
				else {
					while (low < n - 1 && nums[low + 1] == nums[low]) {    //跳过相同的元素
						low++;
					}
					low++;
				}
			}
		}
		return ret;
	}
};

