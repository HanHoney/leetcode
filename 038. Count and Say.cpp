//38. Count and Say
//Easy
//Ä£Äâ

#include <string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string ret("1");
		for (int i = 0; i < n - 1; i++) {
			string str;
			auto b = ret.cbegin();   //·µ»Øconst_iterator
			for (auto e = b; e != ret.cend(); e++) {
				if (*e != *b) {
					str += to_string(e - b) + (*b);
					b = e;
				}
			}
			ret = str + to_string(ret.cend() - b) + (*b);
		}
		return ret;
	}

	string countAndSay1(int n) {    //to_stringº¯Êı
		if (n <= 0) return "";
		string ret("1");
		while (--n) {
			int cnt = 1;
			char ch = ret[0];
			string next;
			for (int i = 1; i<ret.size(); i++) {
				if (ret[i] == ch) {
					cnt++;
				}
				else {
					next += to_string(cnt) + ch;
					ch = ret[i];
					cnt = 1;
				}
			}
			ret = next + to_string(cnt) + ch;
		}
		return ret;
	}
};