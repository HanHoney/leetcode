//77. Combinations
//Medium
//DFS������Ҫk��ѭ��
//n��ѡk�����������

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	vector<vector<int>> combine(int n, int k) {		
		vector<vector<int>> ret;	//���ս��
		if (n < k || k <= 0) return ret;
		vector<int> path;			//�м���
		dfs(ret, path, 1, n, k);
		return ret;
	}

private:
	void dfs(vector<vector<int>> &ret, vector<int> &path, int curr, int n, int k) {
		if (k == 0) {					//�ҵ�һ���Ϸ���
			ret.push_back(path);
			return;
		}
		for (int i = curr; i <= n - k + 1; i++) {   //��֦��i <= n Ҳ����
			path.push_back(i);			//ִ����չ����
			dfs(ret, path, i + 1, n, k - 1);
			path.pop_back();			//��������
		}
	}
};

//
//int main() {
//	vector<vector<int>> ans;
//	Solution s;
//	ans = s.combine(6, 3);
//	for (auto &a : ans) {
//		cout << "[ ";
//		for (auto d : a) {
//			cout << d << " ";
//		}
//		cout << "]\n";
//	}
//	system("pause");
//	return 0;
//}