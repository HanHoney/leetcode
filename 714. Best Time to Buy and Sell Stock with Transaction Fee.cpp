//714. Best Time to Buy and Sell Stock with Transaction Fee
//Medium
//DP
//buy[i]：第i天持有时的最大利润	sell[i]：第i天未持有时的最大利润


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//TC:O(n)	SC:O(n)
	int maxProfit_1(vector<int>& prices, int fee) {
		int n = prices.size();
		if (n<2) return 0;
		vector<int> buy(n, 0);
		vector<int> sell(n, 0);
		buy[0] = -prices[0];
		for (int i = 1; i<n; i++) {
			buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
		}
		return sell[n - 1];
	}

	//优化
	//TC:O(n)	SC:O(1)
	int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		if (n < 2) return 0;
		int buy = -prices[0];
		int sell = 0;
		for (int i = 1; i < n; i++) {
			int tmp = max(buy, sell - prices[i]);
			sell = max(sell, buy + prices[i] - fee);
			buy = tmp;
		}
		return sell;
	}
};
