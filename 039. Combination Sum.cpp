//39. Combination Sum
//Medium
//���ݷ���DFS

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ret;    //���ս��
		if (candidates.size() <= 0) return ret;
		vector<int> curr;			//�м���
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, curr, 0, ret);
		return ret;
	}

private:
	void dfs(vector<int>& candidates, int target, vector<int> &curr, int index, vector<vector<int>> &ret) {
		if (target == 0) {			//�ҵ�һ���Ϸ���
			ret.push_back(curr);
			return;
		}
		for (int i = index; i < candidates.size(); i++) {
			if (target < candidates[i]) return; //��֦
			curr.push_back(candidates[i]);      //ִ����չ����
			dfs(candidates, target - candidates[i], curr, i, ret);
			curr.pop_back();					//��������
		}
	}
};
//
//int main() {
//	vector<int> cdds{ 2,3,5 };
//	int target = 8;
//	Solution s;
//	vector<vector<int>> res = s.combinationSum(cdds, target);
//	for (auto &v : res) {
//		cout << "[ ";
//		for (auto n : v) {
//			cout << n << " ";
//		}
//		cout << "]\n";
//	}
//	system("pause");
//	return 0;
//}