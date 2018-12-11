//45. Jump Game II
//Hard
//Greedy

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int n = nums.size();
		int reach = 0;
		int res = 0;
		if (nums.size() < 2) return res;
		for (int i = 0; i < n;) {
			int tmp = reach;
			while (i <= reach) {   //每次循环reach不更新
				tmp = max(tmp, i + nums[i]);
				i++;
			}
			reach = tmp;
			res++;
			if (reach >= n - 1) return res;
		}
		return -1;             //不能到达终点，返回-1
	}
};