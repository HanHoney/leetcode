//746. Min Cost Climbing Stairs
//Easy
//ע���������~cost������ÿ��̨���ж������ģ���sizeΪn������̨������n+1����

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		vector<int> res(n + 1, 0);
		for (int i = 2; i <= n; i++) {
			res[i] = min(res[i - 2] + cost[i - 2], res[i - 1] + cost[i - 1]);
		}
		return res[n];
	}
};