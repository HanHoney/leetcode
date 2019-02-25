//122. Best Time to Buy and Sell Stock II
//Easy
//Greedy
//ά���������м��ɣ��������

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int ret = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > prices[i - 1])
				ret += prices[i] - prices[i - 1];
		}
		return ret;
	}
};