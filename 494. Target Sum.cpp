//494. Target Sum
//Medium
//DP

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	int findTargetSumWays_DFS(vector<int>& nums, int S) {
		int ret = 0;
		int sum = 0;
		for (auto num : nums) {
			sum += num;
		}
		if (S > sum || S < -sum) return ret;
		dfs(nums, 0, S, ret);
		return ret;
	}
	void dfs(vector<int>& nums, int idx, int target, int& res) {
		if (idx == nums.size()) {
			if (target == 0) res++;
			return;
		}
		dfs(nums, idx + 1, target - nums[idx], res);
		dfs(nums, idx + 1, target + nums[idx], res);
	}
};

//������ȡ��������ΪP,ȡ��������ΪN
//P+N=sum(nums),P-N=S,��2*P=sum+S
//P=(sum+S)/2.0 
//ת��Ϊ�Һ�ΪP�������

class Solution_DP_best {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;
		for (int num : nums) {
			sum += num;
		}
		if (S > sum || S < -sum || (sum + S) % 2 != 0) return 0;
		int target = (sum + S) / 2;
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int num : nums) {
			for (int i = target; i >= num; i--) {
				dp[i] += dp[i - num];
			}
		}
		return dp[target];
	}
};


//��һdp  dp[N+1][2*sum+1]�����-sum,��Сsum,����ƫ����sum��dp[0][sum]=1;
//dp[i][j+sum]=dp[i-1][j+sum-n[i-1]]+dp[i-1][j+sum-dp[i-1]]
//�����Ϊdp[N][S+sum]

class Solution_DP_2 {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = 0;
		for (int num : nums) {
			sum += num;
		}
		if (S > sum || S < -sum || (sum + S) % 2 != 0) return 0;
		int n = nums.size();
		int m = 2 * sum;
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		dp[0][sum] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (j - nums[i - 1] >= 0) {
					dp[i][j] += dp[i - 1][j - nums[i - 1]];
				}
				if (j + nums[i - 1] <= m) {
					dp[i][j] += dp[i - 1][j + nums[i - 1]];
				}
			}
		}
		return dp[n][S + sum];
	}
};
