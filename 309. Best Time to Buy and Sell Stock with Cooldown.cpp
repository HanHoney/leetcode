//309. Best Time to Buy and Sell Stock with Cooldown
//Medium
//DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	//TC:O(n) SC:O(n)
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n < 2) return 0;
		vector<int> buy(n, 0);
		vector<int> sell(n, 0);
		buy[0] = -prices[0];
		buy[1] = max(-prices[0], -prices[1]);
		sell[1] = max(0, prices[1] - prices[0]);
		for (int i = 2; i < n; i++) {
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
			buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
		}
		return sell[n - 1];
	}

	//ÓÅ»¯£ºTC:O(n) SC:O(1)
	int maxProfit_1(vector<int>& prices) {
		int n = prices.size();
		if (n < 2) return 0;
		int buy = -min(prices[0], prices[1]);
		int prev = 0;
		int sell = max(0, prices[1] - prices[0]);
		for (int i = 2; i < n; i++) {
			int tmp = max(sell, buy + prices[i]);
			buy = max(buy, prev - prices[i]);
			prev = sell;
			sell = tmp;
		}
		return sell;
	}
};