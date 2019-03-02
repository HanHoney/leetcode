//118. Pascal's Triangle
//Easy
//Ñî»ÔÈý½Ç

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;
		if (numRows<1) return ret;
		vector<int> pre({ 1 });
		ret.push_back(pre);
		if (numRows == 1) return ret;
		for (int i = 2; i <= numRows; i++) {
			vector<int> curr(i);
			curr[0] = 1;
			curr[i - 1] = 1;
			for (int j = 1; j < i - 1; j++) {
				curr[j] = pre[j - 1] + pre[j];
			}
			ret.push_back(curr);
			pre = curr;
		}
		return ret;
	}
};