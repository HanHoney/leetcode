//123. Best Time to Buy and Sell Stock III
//Hard
//DP

/*
* f[i]表示[0,i]最大利润，g[i]表示[i,n-1]最大利润，0≤i≤n-1
* res=max{f[i]+g[i]}
* TC : O(n)
* SC : O(n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if (n < 2) return 0;
		vector<int> f(n, 0);
		vector<int> g(n, 0);
		for (int i = 1, buy = prices[0]; i < n; i++) {
			buy = min(buy, prices[i]);
			f[i] = max(f[i - 1], prices[i] - buy);
		}
		for (int i = n - 2, sell = prices[n - 1]; i >= 0; i--) {
			sell = max(sell, prices[i]);
			g[i] = max(g[i + 1], sell - prices[i]);
		}
		int ret = 0;
		for (int i = 0; i < n; i++) {
			ret = max(f[i] + g[i], ret);
		}
		return ret;
	}
};