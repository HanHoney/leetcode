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
		if (n == 0) return vector<string>(1,"");
		if (n == 1) return vector<string>(1, "()");
		vector<string> ret;
		string s;
		generate(s, n, n, ret);
		return ret;
	}
	void generate(string str,int left,int right,vector<string> &res) {  //�޷����������ʱ�����ٵ���generate���ݹ���ڡ�
		if (left == 0 && right == 0) {   
			res.push_back(str);
		}
		if (left > 0) {  //��������
			generate(str + "(", left - 1, right, res);
		}
		if (right > 0 && right > left) {   //��������
			generate(str + ")", left, right - 1, res);
		}
		return;   //��ʡ�ԣ�д�����߼�������~
	}
};