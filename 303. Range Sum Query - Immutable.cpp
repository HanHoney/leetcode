//303. Range Sum Query - Immutable
//Easy

#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
	NumArray(vector<int> nums) {
		sum.push_back(0);
		for (auto num : nums) {
			sum.push_back(sum.back() + num);
		}
	}
	int sumRange(int i, int j) {
		return sum[j + 1] - sum[i];
	}
private:
	vector<int> sum;
};

int main() {
	vector<int> nums{ -2,0,3,-5,2,-1 };
	NumArray arr(nums);
	cout << arr.sumRange(0, 2) << endl;
	cout << arr.sumRange(2, 5) << endl;
	cout << arr.sumRange(0, 5) << endl;
	system("pause");
	return 0;
}