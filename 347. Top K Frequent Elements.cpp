//347. Top K Frequent Elements
//Medium
//TC:O(nlogk)	SC:O(n)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>   
using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		if (k >= nums.size()) return nums;
		vector<int> ret;
		unordered_map<int, int> map;
		priority_queue<pair<int, int>> heap;
		for (auto i : nums) {
			map[i]++;
		}
		for (auto it : map) {
			heap.push(make_pair(it.second, it.first));
	//		heap.push({ it.second,it.first });
		}
		for (int i = 0; i < k; i++) {
			ret.push_back(heap.top().second);
			heap.pop();
		}
		return ret;
	}
};


int main() {
	vector<int> nums{ 1,1,2,2,2,3 };
	int k = 2;
	Solution s;
	vector<int> res = s.topKFrequent(nums, k);
	for (auto n : res) {
		cout << n << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
