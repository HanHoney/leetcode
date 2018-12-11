//128. Longest Consecutive Sequence 
//�����������
//Hard
//��sort	��HashSet(�ռ任ʱ��)
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
using namespace std;

class Solution {
public:

	//�� TC:O(nlogn)	SC:O(n)
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


	//TC:O(n)	SC:O(n)
	int longestConsecutive1(vector<int>& nums) {
		unordered_map<int, int> map;
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

/**
	int longestConsecutive1(vector<int>& nums) {
		unordered_map<int, int> map;
		int ret = 0;
		for (int i : nums) {
			if (map.find(i) != map.end()) continue;
			map[i] = 1;
			if (map.find(i - 1) != map.end()) {
				map[i] += map[i - 1];
			}
			if (map.find(i + 1) != map.end()) {
				map[i] += map[i + 1];
			}
		}
		return ret;
	}
**/
	
};

int main() {
	vector<int> nums{ 9,1,4,7,3,-1,0,5,8,-1,6 };
	Solution s;
	cout << s.longestConsecutive1(nums) << endl;
	system("pause");
	return 0;
}