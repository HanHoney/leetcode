//212. Word Search II
//Hard
//¿˚”√Trie£∫208. Implement Trie (Prefix Tree)

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class TrieNode {
public:
	TrieNode *next[26];
	bool isWord;
	TrieNode() {
		for (int i = 0; i < 26; ++i) {
			next[i] = nullptr;
		}
		isWord = false;
	}
	~TrieNode() {
		for (int i = 0; i < 26; ++i) {
			if (next[i] != nullptr) {
				delete next[i];
			}
		}
	}
};

class Trie {
	TrieNode *root;
public:
	Trie() {
		root = new TrieNode();
	}
	~Trie() {
		delete root;
	}
	TrieNode* getRoot() const {
		return root;
	}
	void insert(string word) {
		TrieNode *curr = root;
		for (char ch : word) {
			if (curr->next[ch - 'a'] == nullptr) {
				curr->next[ch - 'a'] = new TrieNode();
			}
			curr = curr->next[ch - 'a'];
		}
		curr->isWord = true;
	}
};

class Solution {
	int row;
	int col;
	int steps[4][2] = {
		{1,0},
		{-1,0},
		{0,1},
		{0,-1}
	};
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		row = board.size();
		col = board[0].size();
		Trie *trie = new Trie();
		for (string word : words) {
			trie->insert(word);
		}
		TrieNode *root = trie->getRoot();
		set<string> wordList;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				dfs(board, i, j, root, "", wordList);
			}
		}
		vector<string> ret;
		for (string word : wordList) {
			ret.emplace_back(word);
		}
		return ret;
	}
	void dfs(vector<vector<char>>& board, int x, int y, TrieNode* curr, string word, set<string>& wordList) {
		if (x < 0 || x >= row || y < 0 || y >= col || board[x][y] == ' ') return;
		if (curr->next[board[x][y] - 'a'] == nullptr) return;
		word = word + board[x][y];
		curr = curr->next[board[x][y] - 'a'];
		if (curr->isWord) {
			wordList.insert(word);
		}
		char ch = board[x][y];
		board[x][y] = ' ';
		for (int i = 0; i < 4; ++i) {
			int dx = x + steps[i][0];
			int dy = y + steps[i][1];
			dfs(board, dx, dy, curr, word, wordList);
		}
		board[x][y] = ch;
	}
};

#if 0

int main() {
	vector<string> words = { "oath","pea","eat","rain" };
	vector<vector<char>> board = { {'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'} };
	Solution s;
	vector<string> ret = s.findWords(board, words);
	for (auto str : ret) {
		cout << str << endl;
	}
	system("pause");
	return 0;
}

#endif