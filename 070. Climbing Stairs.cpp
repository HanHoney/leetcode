//70. Climbing Stairs
//Easy
//쳲���������
//�����ظ����㳬ʱ�������鱣�������ǵݹ�

#include <vector>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {   //���nΪ44���������
		vector<int> res(n + 1, 1);
		for (int i = 2; i <= n; i++) {
			res[i] = res[i - 2] + res[i - 1];
		}
		return res[n];
	}
};