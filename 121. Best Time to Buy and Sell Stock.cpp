//121. Best Time to Buy and Sell Stock
//Easy
//Greedy
//扫描，记录最低买入价格和当前卖出的最高利润

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int ret = 0;
		int buy = prices.front();
		for (auto p : prices) {
			buy = min(p, buy);
			ret = max(ret, p - buy);
		}
		return ret;
	}
};
//
//int main() {
//	vector<int> p{ 7,1,5,3,4,6 };
//	Solution s;
//	cout << s.maxProfit(p) << endl;
//	system("pause");
//	return 0;
//}