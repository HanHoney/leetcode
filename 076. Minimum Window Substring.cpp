//76. Minimum Window Substring
//Hard
//①双指针	TC:O(|S|+|T|)	SC:O(|S|+|T|)

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		string ret;
		if (s.size() == 0 || t.size() == 0 || t.size() > s.size()) return ret;
		unordered_map<char, int> mp;
		for (int i = 0; i < t.size(); i++) {   //可以直接这样初始化
			mp[t[i]]++;
		}
		unordered_map<char, int> tmp;   //用来记录已经找到的字符及个数
		for (auto it:mp) {      
			tmp.insert({ it.first,0 }); //初始化
		}
		int count = t.size();           //需要寻找的字符数
		int minStart = 0;
		int minWin = INT_MAX;
		int left = 0, right = 0;
		while (right < s.size()) {
			if (mp.find(s[right]) != mp.end()) {      //字符在T中存在
				if (tmp[s[right]] < mp[s[right]]) {   //是有效的扩展
					count--;
				}
				tmp[s[right]]++;
			}
			while (count == 0) {   //若此时已经包含T中所有的字符，记录，并尝试将left右移
				if (right - left + 1 < minWin) {
					minWin = right - left + 1;
					minStart = left;
					if (minWin == t.size()) {
						ret = s.substr(minStart, minWin);
						return ret;
					}
				}
				//将left右移
				if (mp.find(s[left]) != mp.end()) {
					if (tmp[s[left]] <= mp[s[left]]) {  //若除掉一个s[left]影响结果，则count++，跳出循环
						count++;
					}
					tmp[s[left]]--;
				}
				left++;
			}
			right++;
		}
		if (minWin != INT_MAX) {
			ret = s.substr(minStart, minWin);
		}
		return ret;				//没有匹配的窗口,也返回""
	}
};
//
//int main() {
//	Solution s;
//	cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
//	system("pause");
//	return 0;
//}