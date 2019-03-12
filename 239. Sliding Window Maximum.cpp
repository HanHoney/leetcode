//239. Sliding Window Maximum
//Hard

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

class Solution {
public:

	//双端队列
	//维护非递增序列的下标
	//保证窗口大小，以及队列中的非递增性
	//TC:O(n)
	//deque存的索引递增，索引对应的元素递减。front是当前窗口内值最大的数的索引。
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ret;
		if (k == 0) return ret;
		if (k == 1) return nums;
		deque<int> dq;      
		for (int i = 0; i < nums.size(); i++) {
			if (dq.front() == i - k) {								//维护窗口大小
				dq.pop_front();
			}
			while (!dq.empty() && nums[dq.back()] < nums[i]) {		//维护索引对应元素递减
				dq.pop_back();
			}
			dq.push_back(i);
			if (i >= k - 1) {
				ret.push_back(nums[dq.front()]);
			}
		}
		return ret;
	}

	//使用最大堆priority_queue，堆顶为top()而不是front()
	//TC:O(nlogn) 
	/*
	时间复杂度不是O(nlogk)的原因：pq.size()可能达到n(当是递增序列)，pq规模不能单方面取决于窗口大小k，还要受数据本身影响。 
	因为只删除最大根中对应下标超出窗口位置的项，而不维护pq大小为k。
	*/
	vector<int> maxSlidingWindow_PQ(vector<int>& nums, int k) {
		vector<int> ret;
		if (k == 0) return ret;
		if (k == 1) return nums;
		priority_queue<pair<int, int>> pq;
		for (int i = 0; i < nums.size(); i++) {
			while (!pq.empty() && pq.top().second <= i - k) {
				pq.pop();
			}
			pq.push(make_pair(nums[i], i));
			if (i >= k - 1) {
				ret.push_back(pq.top().first);
			}
		}
		return ret;
	}
};