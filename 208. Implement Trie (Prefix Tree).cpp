//208. Implement Trie (Prefix Tree)
//Medium
//×ÖµäÊ÷/Ç°×ºÊ÷

#include <iostream>
using namespace std;

class TrieNode {
public:
	TrieNode *next[26];
	bool isWord;
	TrieNode() {
		memset(next, 0, sizeof(next));
		isWord = false;
	}
	~TrieNode() {
		for (auto i : next) {
			if (i) delete i;
		}
	}
};

class Trie {

	TrieNode *root;
public:

	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}
	~Trie() {
		delete root;
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *p = root;
		for (auto c : word) {
			if (p->next[c - 'a'] == nullptr) {
				p->next[c - 'a'] = new TrieNode();
			}
			p = p->next[c - 'a'];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode *p = root;
		for (auto c : word) {
			if (p->next[c - 'a'] == nullptr) {
				return false;
			}
			p = p->next[c - 'a'];
		}
		return p->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode *p = root;
		for (auto c : prefix) {
			if (p->next[c - 'a'] == nullptr) {
				return false;
			}
			p = p->next[c - 'a'];
		}
		return true;
	}
};