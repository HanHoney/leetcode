//438. Find All Anagrams in a String
//Easy
//Hash Table 两个哈希表可以通过==比较

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> ret;
		if (p.size()>s.size()) return ret;
		vector<int> smap(26, 0);
		vector<int> pmap(26, 0);
		for (int i = 0; i < p.size(); i++) {
			smap[s[i] - 'a']++;
			pmap[p[i] - 'a']++;
		}
		if (smap == pmap) ret.push_back(0);
		for (int i = p.size(); i < s.size(); i++) {
			smap[s[i - p.size()] - 'a']--;
			smap[s[i] - 'a']++;
			if (smap == pmap) {
				ret.push_back(i - p.size() + 1);
			}
		}
		return ret;
	}
};