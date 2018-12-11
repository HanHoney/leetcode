//78. Subsets
//Medium
//���ⲻҪ���Ӽ��ڲ�Ԫ�طǽ������У�����Ҫsort()
//�ٷǵݹ� �ڵݹ� ��ƥ�������λ��
/* http://www.cnblogs.com/TenosDoIt/p/3451902.html */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	//�ٷǵݹ�
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret(1);               //��ʼ����ֻ��һ���ռ�
		if (nums.empty()) return ret;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {   //�������ÿ������
			int len = ret.size();
			for (int j = 0; j < len; j++) {       //����������ӵ��������е��Ӽ��У�����֮ǰ���Ӽ��γ��µ��Ӽ�
				ret.push_back(ret[j]);
				ret.back().push_back(nums[i]);
			}
		}
		return ret;
	}

	//�ڵݹ飨DFS��
	//��������ÿ��Ԫ�ض���ѡ�Ͳ�ѡ���ֲ�����
	vector<vector<int>> subsets1(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		dfs(ret, tmp, nums, 0);
		return ret;
	}
	void dfs(vector<vector<int>> &ret, vector<int> &tmp, vector<int> &nums, int i) {
		if (i == nums.size()) {   //Ҷ�ӽ��
			ret.push_back(tmp);
			return;
		}
		/*
		//ѡ��nums[i]
		tmp.push_back(nums[i]);
		dfs(ret, tmp, nums, i + 1);
		//��ѡ��nums[i]
		tmp.pop_back();
		dfs(ret, tmp, nums, i + 1);
		*/
		
		//��ѡ��nums[i]
		dfs(ret, tmp, nums, i + 1);
		//ѡ��nums[i]
		tmp.push_back(nums[i]);
		dfs(ret, tmp, nums, i + 1);
		//rollback
		tmp.pop_back();
	}

	//�۶�����
	//TRUE FALSE��Ӧ������λ����

};

//
//int main() {
//	vector<int> nums{ 1,2,3 };
//	vector<vector<int>> res;
//	Solution s;
//	res = s.subsets1(nums);
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