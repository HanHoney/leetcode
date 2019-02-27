//560. Subarray Sum Equals K
//Medium
//要求数连续，到第i个数的累加和位S[i]，则第i位到第j位的和为S[j]-S[i-1]
//使用哈希表 TC:O(n) SC:O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int count = 0;
		int sum = 0;
		unordered_map<int, int> map;
		map[0] = 1;
		for (int num : nums) {
			sum += num;
			count += map[sum - k];
			map[sum]++;
		}
		return count;
	}
};

#if 0
int main() {
	vector<int> nums{ 1,1,1 };
	int k = 2;
	Solution s;
	cout << s.subarraySum(nums, k) << endl;
	system("pause");
	return 0;
}
#endif