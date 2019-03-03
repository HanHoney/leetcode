//220. Contains Duplicate III
//Medium

/*

��
set ���򼯺�
lower_bound ����iterator 

��Ͱ����

��note��
test case:
[2147483647,-2147483647]
1
2147483647

int�����
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:

	//����set�������Ժ�lower_bound����
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

	//����Ͱ����
	bool containsNearbyAlmostDuplicate_buckets(vector<int>&nums, int k, int t) {
		if (nums.size() <= 1 || k <= 0 || t < 0) return false;
		int m = nums[0];
		for (int num : nums) {
			m = min(num, m);
		}
		unordered_map<long long, long long> buckets;
		for (int i = 0; i < nums.size(); i++) {
			if (i > k) {
				long long key = ((long long)nums[i - k - 1] - m) / ((long long)t + 1);	//t����Ϊ0
				buckets.erase(key);
			}
			long long key = ((long long)nums[i] - m) / ((long long)t + 1);
			if (buckets.find(key) != buckets.end()) return true;	//ͬһ��Ͱ������ֵΪt
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
