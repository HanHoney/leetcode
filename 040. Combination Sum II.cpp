//40. Combination Sum II
//Medium
//DFS

/*
1. Each number in candidates may only be used once in the combination.
2. The solution set must not contain duplicate combinations.
Ϊ�˱�֤�ڶ��㣺
��ʹ��set ��skip: i > start && candidates[i] == candidates[i - 1]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ret;	 //���ս��
		if (candidates.empty()) return ret;
		sort(candidates.begin(), candidates.end());
		vector<int> curr;			 //�м���
		dfs(candidates, target, curr, ret, 0);
		return ret;
	}
private:
	void dfs(vector<int> &candidates, int target, vector<int> &curr, vector<vector<int>> &ret, int start) {
		if (target == 0) {			//�ҵ�һ���Ϸ���
			ret.push_back(curr);
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			if (i > start && candidates[i] == candidates[i - 1]) continue;  //skip���ܿ��ظ���
			if (candidates[i] > target) return;			//��֦
			curr.push_back(candidates[i]);				//ִ����չ����
			dfs(candidates, target - candidates[i], curr, ret, i + 1);		//i+1��֤Ԫ�ز��ظ�ʹ��
			curr.pop_back();							//��������
		}
	}
};
//
//int main() {
//	vector<int> date{ 1,5,2,1,10,6,7 };
//	int target = 8;
//	Solution s;
//	vector<vector<int>> res = s.combinationSum2(date, target);
//	for (auto &r : res) {
//		cout << "[ ";
//		for (auto n : r) {
//			cout << n << " ";
//		}
//		cout << "]\n";
//	}
//	system("pause");
//	return 0;
//}