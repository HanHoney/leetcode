// 14. Longest Common Prefix
// Easy
// DC || Trie

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class TrieNode {
public:
	TrieNode *next[26];
	bool isEnd;
	int index;
	TrieNode() {
		for (int i = 0; i < 26; ++i) {
			next[i] = nullptr;
		}
		isEnd = false;
		index = -1;
	}
	~TrieNode() {
		for (int i = 0; i < 26; ++i) {
			delete next[i];
		}
	}
};

class Trie {
public:
	TrieNode *root;
	Trie() {
		root = new TrieNode();
	}
	~Trie() {
		TrieNode *curr = root;
		while (curr->index != -1) {
			TrieNode *child = curr->next[curr->index];
			delete curr;
			curr = child;
		}
	}
	void addWord(string str) {
		TrieNode *curr = root;
		for (auto ch : str) {
			if (curr->next[ch - 'a'] == nullptr) {
				curr->next[ch - 'a'] = new TrieNode();
			}
			curr->index = ch - 'a';
			curr = curr->next[ch - 'a'];
		}
		curr->isEnd = true;
	}
	void addWordOnSingleBranch(string str) {
		TrieNode *curr = root;
		for (auto ch : str) {
			if (curr->next[ch - 'a'] == nullptr) {
				curr->isEnd = true;
				break;
			}
			curr = curr->next[ch - 'a'];
		}
		curr->isEnd = true;
	}
};

class Solution_Trie {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		if (strs.size() == 1) return strs[0];
		int minlen = strs[0].size();
		int minidx = 0;
		for (int i = 1; i < strs.size(); ++i) {
			if (strs[i].size() < minlen) {
				minlen = strs[i].size();
				minidx = i;
			}
		}
		if (minidx != 0) swap(strs[0], strs[minidx]);
		Trie *trie = new Trie();
		trie->addWord(strs[0]);		
		for (int i = 1; i < strs.size(); ++i) {
			trie->addWordOnSingleBranch(strs[i]);
		}
		string ret = "";
		TrieNode *curr = trie->root;
		while (!curr->isEnd) {
			ret = ret + (char)('a' + curr->index);
			curr = curr->next[curr->index];
		}
		return ret;
	}
};

class Solution_DC {
public:

	//DC
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() <= 0) {
			return "";
		}
		return longestCommonPrefix(strs, 0, strs.size() - 1);
	}
	string longestCommonPrefix(vector<string>& strs, int left, int right) {
		if (left == right) return strs[left];
		int mid = (left + right) / 2;
		string s1 = longestCommonPrefix(strs, left, mid);
		string s2 = longestCommonPrefix(strs, mid + 1, right);
		for (int i = 0; i < min(s1.size(), s2.size()); i++) {
			if (s1[i] != s2[i]) {
				return s1.substr(0, i);
			}
		}
		return s1.size()<s2.size() ? s1 : s2;
	}

};