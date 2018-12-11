//6. ZigZag Conversion

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		int len = s.length();
		
		//无需做处理的情况
		if (numRows <= 1 || numRows >= len) {
			return s; 
		}
	//	int numCols = (len - 1) / (numRows - 1) + 1;
		vector<string> str(numRows);   //每行是一个string
		int row = 0;
		int direct = 1;
		for (int i = 0; i < len; i++) {
			if (row == 0) {            //向下,行数加1
				direct = 1;
			}
			if (row == numRows - 1) {
				direct = -1;             //斜向上，行数减1
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