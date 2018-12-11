//90. Subsets II
//Medium
//�ٷǵݹ� �ڵݹ�
/* http://www.cnblogs.com/TenosDoIt/p/3451902.html */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		vector<vector<int>> ret(1);
		if (nums.empty()) return ret;
		sort(nums.begin(), nums.end());
		int lastNum = nums[0];			//��һ��Ԫ��
		int cnt = 1;					//��¼���ֲ���Ҫ�ڼ����Ӽ��Ļ�����insert�������Ӽ���
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != lastNum) {	//�µ�Ԫ�أ�����������ǡ�
				lastNum = nums[i];
				cnt = ret.size();
			}
			//������һ��Ԫ��һ����ֻ��Ҫ����һ���²������Ӽ�������γ��µ�Ԫ�ء�
			int size = ret.size();
			for (int j = size - cnt; j < size; j++) {
				ret.push_back(ret[j]);
				ret.back().push_back(nums[i]);
			}
		}
		return ret;
	}

	vector<vector<int>> subsetsWithDup1(vector<int> &nums) {
		vector<vector<int>> ret;
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		dfs(ret, tmp, nums, 0);
		return ret;
	}
	void dfs(vector<vector<int>> &ret, vector<int> &tmp, vector<int> &nums, int idx) {
		if (idx == nums.size()) {
			ret.push_back(tmp);
			return;
		}
		//��ѡ��nums[idx]
		dfs(ret, tmp, nums, idx + 1);

		int cnt = 0;		//��ǰԪ����ǰ���ֵĴ�������Ҫ�䶯���Ӽ��к��и�Ԫ�صĸ�����
		while (idx - cnt >= 0 && nums[idx - cnt] == nums[idx]) cnt++;
		cnt--;
		if (cnt == 0 || tmp.size() >= cnt && tmp[tmp.size() - cnt] == nums[idx]) {
			//ѡ��nums[idx]
			tmp.push_back(nums[idx]);
			dfs(ret, tmp, nums, idx + 1);
			tmp.pop_back();
		}
	}
};
//
//int main() {
//	vector<int> nums{ 1,2,2 };
//	Solution s;
//	vector<vector<int>> res = s.subsetsWithDup1(nums);
//	for (auto &v : res) {
//		cout << "[ ";
//		for (auto n : v) {
//			cout << n << " ";
//		}
//		cout << "]" << endl;
//	}
//	system("pause");
//	return 0;
//}

