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
		unordered_map<int, int> map;
		for (int num : nums) {
			++map[num];
		}
		//小根堆，按照pair.first排序，即first代表频率。
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		for (auto it : map) {
			if (pq.size() < k) {
				pq.push(make_pair(it.second, it.first));
			}
			else if (pq.size() == k && it.second > pq.top().first) {
				pq.pop();
				pq.push(make_pair(it.second, it.first));
			}
		}
		vector<int> ret;
		while (!pq.empty()) {
			ret.push_back(pq.top().second);
			pq.pop();
		}
		return ret;
	}
};

//
//int main() {
//	vector<int> nums{ 1,1,2,2,2,3 };
//	int k = 2;
//	Solution s;
//	vector<int> res = s.topKFrequent(nums, k);
//	for (auto n : res) {
//		cout << n << " ";
//	}
//	cout << endl;
//	system("pause");
//	return 0;
//}
