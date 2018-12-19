//215. Kth Largest Element in an Array
//Medium
//①快排partition思想	②sort排序	③堆排序

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	//TC:O(n)
	int findKthLargest(vector<int>& nums, int k) {
		int left = 0, right = nums.size() - 1;
		int pos = partition(nums, left, right);
		while (pos != k - 1) {
			if (pos<k - 1) pos = partition(nums, pos + 1, right);
			else pos = partition(nums, left, pos - 1);
		}
		return nums[pos];
	}

	//TC:O(nlogn)	SC:O(1)
	int findKthLargest1(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() - k];
	}

	//最大堆
	//TC:O(n)	SC:O(n)
	int findKthLargest2(vector<int>& nums, int k) {
		priority_queue<int> pq(nums.begin(), nums.end());		//内部维护递增顺序
		for (int i = 0; i < k - 1; i++) {
			pq.pop();
		}
		return pq.top();
	}

private:
	static int partition(vector<int>& nums, int left, int right) {
		int pivot = nums[right];
		int l = left, r = right - 1;
		while (l <= r) {
			if (nums[l]<pivot&&nums[r]>pivot) {
				swap(nums[l++], nums[r--]);
			}
			while (l <= r && nums[l] >= pivot) l++;
			while (l <= r && nums[r] <= pivot) r--;
		}
		swap(nums[l], nums[right]);
		return l;
	}
};

int main() {
	vector<int> nums{ 3,2,1,5,6,4,4,6,5 };
	int k = 5;
	Solution s;
	cout << s.findKthLargest(nums, k) << endl;
	system("pause");
	return 0;
}