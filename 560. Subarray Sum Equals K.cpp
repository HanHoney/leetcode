//560. Subarray Sum Equals K
//Medium
//Ҫ��������������i�������ۼӺ�λS[i]�����iλ����jλ�ĺ�ΪS[j]-S[i-1]
//ʹ�ù�ϣ�� TC:O(n) SC:O(n)

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