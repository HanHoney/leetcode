//22. Generate Parentheses
//Medium
//��ĸ����ǿ������������ɺ���������λ��������������������ڵ����������������ɴ�ӡ���š�
//left��δ��ӡ����������  right��δ��ӡ����������

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ret;
		string path = "";
		dfs(ret, path, n, n);
		return ret;
	}
	void dfs(vector<string>& ret, string path, int left, int right) {
		if (left < 0 || left > right) return;
		if (left == 0 && right == 0) {
			ret.emplace_back(path);
		}
		path.push_back('(');
		dfs(ret, path, left - 1, right);
		path.back() = ')';
		dfs(ret, path, left, right - 1);
	}
};