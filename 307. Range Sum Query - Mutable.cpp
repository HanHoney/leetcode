//307. Range Sum Query - Mutable
//Medium

#include <iostream>
#include <vector>
using namespace std;


class NumArray {
public:
	NumArray(vector<int> nums) {
		sum.push_back(0);
		for (int num : nums) {
			vals.push_back(num);
			sum.push_back(sum.back() + num);
		}
	}
	void update(int i, int val) {
		int tmp = val - vals[i];
		vals[i] = val;
		for (int idx = i + 1; idx < sum.size(); idx++) {
			sum[idx] += tmp;
		}
	}
	int sumRange(int i, int j) {
		return sum[j + 1] - sum[i];
	}

private:
	vector<int> sum;
	vector<int> vals;
};

int main() {
	vector<int> nums{ 1,3,5 };
	NumArray arr(nums);
	cout << arr.sumRange(0, 2) << endl;
	arr.update(1, 2);
	cout << arr.sumRange(0, 2) << endl;
	system("pause");
	return 0;
}