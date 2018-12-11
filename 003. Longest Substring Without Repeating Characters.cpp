//3. Longest Substring Without Repeating Characters

#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {      //没用map，双层循环
public:
	int lengthOfLongestSubstring(string s) {
		int maxlen = 0;
		int cnt = 0;
		int flag[256] = { 0 };       //ASCII码+扩展ASCII码
		for(int i = 0; i < s.size(); i++) {
			cnt = 0;
			memset(flag, 0, sizeof(flag));   //每轮重置
			for (int j = i; j < s.size(); j++) {
				if (flag[s[j]] == 0) {
					flag[s[j]] = 1;
					cnt++;
				}
				else break;
			}
			if (cnt > maxlen) {
				maxlen = cnt;
			}
		}
		return maxlen;
	}

	// ☆ 一次遍历 ☆
	//同时维护两个索引
	int lengthOfLongestSubstring1(string s) {
		int pos = -1;
		int maxlen = 0;
		int flag[256];
		memset(flag, -1, sizeof(flag));
		for (int i = 0; i < s.size(); i++) {
			if (flag[s[i]] != -1 && pos < flag[s[i]]) {
				pos = flag[s[i]];     //跳到最后一个重复元素的位置
			}
			if (i - pos > maxlen) {
				maxlen = i - pos;
			}
			flag[s[i]] = i;
		}
		return maxlen;
	}
};

