//3. Longest Substring Without Repeating Characters
//Medium
//related topics: two pointers;sliding window

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {      
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> dict(256, -1);	//ASCII码个数是256，记录每个字符最后一次出现的位置
		int ret = 0;
		int left = -1;
		for (int i = 0; i < s.size(); i++) {
			if (dict[s[i]] > left) {
				left = dict[s[i]];
			}
			dict[s[i]] = i;
			ret = max(ret, i - left);
		}
		return ret;
	}
};

