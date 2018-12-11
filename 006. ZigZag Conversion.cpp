//6. ZigZag Conversion

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.length();
		
		//��������������
		if (numRows <= 1 || numRows >= len) {
			return s; 
		}
	//	int numCols = (len - 1) / (numRows - 1) + 1;
		vector<string> str(numRows);   //ÿ����һ��string
		int row = 0;
		int direct = 1;
		for (int i = 0; i < len; i++) {
			if (row == 0) {            //����,������1
				direct = 1;
			}
			if (row == numRows - 1) {
				direct = -1;             //б���ϣ�������1
			}
			str[row] += s[i];
			row += direct;
		}
		string res;
		for (int i = 0; i < numRows; i++) {
			res += str[i];
		}
		return res;
	}
};
/*
int main() {
	string s;
	int r;

	Solution sol;
	s = "PAYPALISHIRING";
	r = 3;
	cout << sol.convert(s, r)<<endl;
	system("pause");
}
*/