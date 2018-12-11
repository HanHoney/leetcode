//96. Unique Binary Search Trees
//Medium

//①递归法 ②公式法
//TC: ①O(n^2) ②O(n)
//SC: ①O(n)   ②O(1)
//最大合法输入为19，否则溢出

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//long long numTrees1(int n) {
	//	vector<long long> res(n + 1, 0);
	//	res[0] = 1;
	//	res[1] = 1;
	//	for (int i = 2; i <= n; i++) {
	//		for (int j = 0; j < i; j++) {
	//			res[i] += res[j] * res[i - j - 1];
	//		}
	//	}
	//	return res[n];
	//}

	//①递归法
	//存结果，减少重复计算
	int numTrees(int n) {
		if (n == 0) return 1;
		vector<int> res(n + 1, 0);
		res[0] = 1;
		res[1] = 1;
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j < i; j++) {
				res[i] += res[j] * res[i - j - 1];
			}
		}
		return res[n];
	}

	//②公式法（卡特兰数）
	//C(0)=1 ,C(n+1)=2(2n+1)/(n+2)*C(n)
	int numTrees1(int n) {
		long long ret = 1;	//注意必须是long long类型，否则计算公式中ret*(4i+2)会溢出
		for (int i = 0; i < n; i++) {
			ret = ret * (4 * i + 2) / (i + 2);
		}
		return ret;
	}
};

//
//int main() {
//	int n;
//	while (cin >> n) {
//		Solution s;
//		cout << s.numTrees(n) << " " << s.numTrees1(n) << endl;
//	}
////	system("pause");
//	return 0;
//}