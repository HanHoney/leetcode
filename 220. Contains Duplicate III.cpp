//220. Contains Duplicate III
//Medium

/*

①
set 有序集合
lower_bound 返回iterator 

②桶排序

【note】
test case:
[2147483647,-2147483647]
1
2147483647

int会溢出
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:

	//利用set的有序性和lower_bound函数
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (nums.size() <= 1 || k <= 0 || t < 0) return false;
		set<long long> s;
		for (int i = 0; i < nums.size(); i++) {
			if (i > k) {
				s.erase(nums[i - k - 1]);
			}
			auto low = s.lower_bound((long long)nums[i] - t);
			if (low != s.end() && *low <= (long long)nums[i] + t) {
				return true;
			}
			s.insert(nums[i]);
		}
		return false;
	}

	//利用桶排序
	bool containsNearbyAlmostDuplicate_buckets(vector<int>&nums, int k, int t) {
		if (nums.size() <= 1 || k <= 0 || t < 0) return false;
		int m = nums[0];
		for (int num : nums) {
			m = min(num, m);
		}
		unordered_map<long long, long long> buckets;
		for (int i = 0; i < nums.size(); i++) {
			if (i > k) {
				long long key = ((long long)nums[i - k - 1] - m) / ((long long)t + 1);	//t可能为0
				buckets.erase(key);
			}
			long long key = ((long long)nums[i] - m) / ((long long)t + 1);
			if (buckets.find(key) != buckets.end()) return true;	//同一个桶，最大差值为t
			if (buckets.find(key - 1) != buckets.end() && nums[i] - buckets[key - 1] <= t) {
				return true;
			}
			if (buckets.find(key + 1) != buckets.end() && buckets[key + 1] - nums[i] <= t) {
				return true;
			}
			buckets[key] = (long long)nums[i];
		}
		return false;
	}
};
