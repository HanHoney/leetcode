//300. Longest Increasing Subsequence
//�����������(LIS)
//Medium

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	//��DP
	//TC:O(n^2)	SC:O(n)
	//dp[i]=max(dp[i],dp[j]+1)&&nums[j]<nums[i]
	//init:dp[i]=1
	int lengthOfLIS(vector<int>& nums) {
		if (nums.empty()) return 0;
		vector<int> dp(nums.size(), 1);
		int ret = 1;
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ret = max(ret, dp[i]);
		}
		return ret;
	}

	//�ڽ��װ� TC:O(nlogn)???
};

//
//int main() {
//	vector<int> nums{ 10,9,2,5,3,7,101,18 };
//	Solution s;
//	cout << s.lengthOfLIS(nums) << endl;
//	system("pause");
//	return 0;
//}