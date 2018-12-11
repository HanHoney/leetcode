//49. Group Anagrams
//Medium
//（不是回文！！注意理解题意）
//两个str排序，得到的str相同，则为anagrams
//哈希表 unordered_map


#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>  //hashmap
using namespace std;

class Solution {
public:
	
	//TLE 超时。。改进为一次循环
	vector<vector<string>> groupAnagrams_TLE(vector<string>& strs) {
		vector<vector<string>> res;
		if (strs.size() < 2) {
			res.push_back(strs);
			return res;
		}
		vector<string> key;
		key.push_back(strs[0]);
		res.push_back(key);
		for (int i = 1; i < strs.size(); i++) {
			bool flag = false;
			for (int j = 0; j < key.size(); j++) {
				if (isAnagrams(strs[i], key[j])) {
					res[j].push_back(strs[i]);
					flag = true;
					break;
				}
			}
			if (!flag) {
				key.push_back(strs[i]);
				vector<string> tmp;
				tmp.push_back(strs[i]);
				res.push_back(tmp);
			}
		}
		return res;
	}
	bool isAnagrams(string s1, string s2) {  //两个str排序，得到的str相同，则为anagrams
		string s3 = s1, s4 = s2;
		sort(s3.begin(), s3.end());
		sort(s4.begin(), s4.end());
		if (s3 == s4) return true;
		return false;
	}
	/****
	bool isPlalindrome(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		int len = s1.size();
		char c = s1[0];
		for (int i = 0; i < len; i++) {
			if (s2[i] == c) {
				if (s2.substr(i, len - i) == s1.substr(0, len - i) && s2.substr(0, i) == s1.substr(len - i, i))
					return true;
			}
		}
		return false;
	}
	***/

	//Time:20ms 更快【best】
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ret;
		if (strs.size() < 2) {
			ret.push_back(strs);
			return ret;
		}
		unordered_map<string, vector<string>> map;
		for (string str : strs) {
			string s = str;
			sort(s.begin(), s.end());
			map[s].push_back(str);
		}
		for (auto it : map) {
			ret.push_back(it.second);
		}
		return ret;
	}

	//Time:100ms+
	vector<vector<string>> groupAnagrams1(vector<string>& strs) {
		vector<vector<string>> res;
		if (strs.size() < 2) {
			res.push_back(strs);
			return res;
		}
		unordered_map<string, vector<string>> m;
		for (string str : strs) {
			vector<int> cnt(26, 0);    //vector注意初始化，下标合理性
			for(char c:str){
				cnt[c - 'a']++;
			}
			string count="";
			for (int i : cnt) {
				count += to_string(i) + "/";
			}
			m[count].push_back(str);
		}
		for (auto a : m) {
			res.push_back(a.second);
		}
		return res;
	}
};
