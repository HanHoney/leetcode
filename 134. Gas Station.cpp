//134. Gas Station
//Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//TC:O(n^2) SC:O(1)
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n = gas.size();
		for (int i = 0; i<n; i++) {
			if (gas[i] >= cost[i]) {
				int val = 0;
				for (int j = 0; j<n; j++) {
					val += gas[(i + j) % n];
					val -= cost[(i + j) % n];
					if (val<0) break;
				}
				if (val >= 0) {
					return i;
				}
			}
		}
		return -1;
	}

	//½øÒ»²½£¬TC:O(n) SC:O(1)
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total = 0, sum = 0;
		int j = -1;
		for (int i = 0; i<gas.size(); i++) {
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (sum < 0) {
				j = i;
				sum = 0;
			}
		}
		return total >= 0 ? j + 1 : -1;
	}
};