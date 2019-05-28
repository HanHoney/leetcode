//128. Longest Consecutive Sequence 
//�����������
//Hard
//��sort	�ڹ�ϣ��(�ռ任ʱ��)

/****************************
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
Your algorithm should run in O(n) complexity.

Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
****************************/


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:

	//�� TC:O(nlogn)	SC:O(1)
	int longestConsecutive(vector<int>& nums) {
		if (nums.empty()) return 0;
		sort(nums.begin(), nums.end());
		int ret = 1;
		int tmp = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != nums[i - 1]) {	//�ظ���Ԫ������
				if (nums[i] == nums[i - 1] + 1) {
					tmp++;
				}
				else {
					ret = max(ret, tmp);
					tmp = 1;
				}
			}
		}
		ret = max(ret, tmp);
		return ret;
	}


	//�� TC:O(n)	SC:O(n)
	//unordered_map����ʹ��[]������insert������intĬ��ֵΪ0
	int longestConsecutive1(vector<int>& nums) {
		unordered_map<int, int> map;	//���ڹ�ϣ��
		int ret = 0;
		for (int i : nums) {
			if (map[i] == 0) {
				map[i] = map[i - 1] + map[i + 1] + 1;
				map[i - map[i - 1]] = map[i];	//���ݵ�����
				map[i + map[i + 1]] = map[i];
				ret = max(ret, map[i]);
			}
		}
		return ret;
	}


	int longestConsecutive2(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		unordered_set<int> s;
		for (auto i : nums) {	//�޳��ظ�Ԫ��
			s.insert(i);
		}
		int ret = 1;
		//���������죬ͬʱ�Ƴ��Ѿ�ʹ�õ�Ԫ��
		for (auto i : nums) {
			int tmp = 1;
			for (int j = i - 1; s.find(j) != s.end(); j--) {
				s.erase(j);
				tmp++;
			}
			for (int j = i + 1; s.find(j) != s.end(); j++) {
				s.erase(j);
				tmp++;
			}
			ret = max(ret, tmp);
		}
		return ret;
	}
	
};

//
//int main() {
//	vector<int> nums{ 9,1,4,7,3,-1,0,5,8,-1,6 };
//	Solution s;
//	cout << s.longestConsecutive(nums) << endl;
//	cout << s.longestConsecutive1(nums) << endl;
//	cout << s.longestConsecutive2(nums) << endl;
//	system("pause");
//	return 0;
//}
