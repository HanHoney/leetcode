//16. 3Sum Closest

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ret;
		int currmin = INT_MAX;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i > 0 && nums[i - 1] == nums[i])     //skip
				continue;
			int a = nums[i];
			int low = i + 1;
			int high = nums.size() - 1;
			while (low < high) {
				int b = nums[low];
				int c = nums[high];
				int sum = a + b + c;
				if (sum == target)
					return target;
				if (abs(sum - target) < currmin) {
					currmin = abs(sum - target);
					ret = sum;
				}
				if (sum < target) {
					while (low < nums.size() - 1 && nums[low] == nums[low + 1]) {
						low++;
					}
					low++;
				}
				else {
					while (high > i + 1 && nums[high] == nums[high - 1]) {
						high--;
					}
					high--;
				}
			}
		}
		return ret;
	}


	/******
	int threeSumClosest_1(vector<int> &num, int target) {
		std::sort(num.begin(), num.end());
		int min{ INT_MAX }, sum{ 0 }, tmpsum{ 0 };
		for (auto it = num.cbegin(); it != num.cend(); ++it)
			for (auto b = std::next(it), e = std::prev(num.cend()); b<e; tmpsum > target ? --e : ++b)
				if ((tmpsum = *it + *b + *e) == target) return target;
				else if (std::abs(tmpsum - target) < min) { sum = tmpsum; min = std::abs(tmpsum - target); }
				return sum;
	}
	*******/
};