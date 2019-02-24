//127. Word Ladder
//Medium
//为避免超时，使用哈希结构记录单词，查找消耗O(1)

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
	//BFS
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> wordDict(wordList.begin(), wordList.end());
		wordDict.erase(beginWord);
		if (wordDict.find(endWord) == wordDict.end()) {
			return 0;
		}
		queue<string> q;
		q.push(beginWord);
		int ladder = 1;
		while (!q.empty()) {
			int n = q.size();
			for (int i = 0; i < n; i++) {
				string curr = q.front();
				q.pop();
				if (curr == endWord) {
					return ladder;
				}
				addWords(curr, q, wordDict);
			}
			ladder++;
		}
		return 0;
	}
private:
	void addWords(string curr, queue<string>& q, unordered_set<string>& wordDict) {
		for (int i = 0; i < curr.size(); i++) {
			char c = curr[i];
			for (int j = 0; j < 26; j++) {
				curr[i] = 'a' + j;
				if (wordDict.find(curr) != wordDict.end()) {
					q.push(curr);
					wordDict.erase(curr);
				}
			}
			curr[i] = c;
		}
	}
};

