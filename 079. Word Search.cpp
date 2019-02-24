//79. Word Search
//Medium
//DFS backtracking(回溯法)
//【异或短路->剪枝！】

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>> &board, string word) {
		if (word.empty()) return true;
		if (board.empty() || board[0].empty()) return false;
		m = board.size();
		n = board[0].size();
		if (m*n < word.size()) return false;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (dfs(board, i, j, word, 0)) {
					return true;
				}
			}
		}
		return false;
	}
private:
	int m;
	int n;
	int steps[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
	bool dfs(vector<vector<char>>& board, int row, int col, string word, int idx) {
		if (idx == word.size()) return true;
		if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[idx]) {
			return false;
		}
		char tmp = board[row][col];
		board[row][col] = '#';
		bool ret = false;
		for (int i = 0; i < 4; i++) {
			ret = ret || dfs(board, row + steps[i][0], col + steps[i][1], word, idx + 1);
		}
		board[row][col] = tmp;
		return ret;
	}
};
