//55. Jump Game
//Medium
//Greedy

#include <vector>
using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int reach = 0;
		for (int i = 0; i <= reach; i++) {   //reach在不断变化，不断扩展reach，探寻最大的可及范围
			reach = reach < i + nums[i] ? i + nums[i] : reach;
			if (reach >= n - 1) return true;
		}
		return false;
	}
};