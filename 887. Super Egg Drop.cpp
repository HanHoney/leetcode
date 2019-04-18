//887. Super Egg Drop
//Hard

//DP
//dp[k][m] = dp[k-1][m-1] (���ˣ����Ͳ���)+ dp[k][m-1] (û�ƣ����߲���) +1(��ǰ��);	
//k������ m������ �ܲ��Ե������¥��
//dp[k][0] = dp[0][m] = 0;
//�ɹ����Ե���˼�ǣ�����ڵ�f�㲻���Ƶ���f��ֵ��0��dp[k][m]֮�䣬���۾����f�Ƕ��٣���������k����������m������õ����f��ֵ��
//��m�ε���¥�����ɵ�m-1�ξ������ڸ���dp[k]ʱ��Ҫ��һ�ֵ�dp[k-1]��dp[k]������k�ǴӴ���С�ݼ�������
//TC:O(KN)	SC:O(K)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int superEggDrop(int K, int N) {
		if (K == 1) return N;
		vector<int> dp(K + 1, 0);
		int m = 0;
		while (dp[K] < N) {
			++m;
			for (int i = K; i > 0; --i) {
				dp[i] += dp[i - 1] + 1;
			}
		}
		return m;
	}
};