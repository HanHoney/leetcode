//37. Sudoku Solver
//Hard
//DFS

#include <iostream>
#include <vector>
using namespace std;

class Solution {

	bool row[9][9] = { false };
	bool col[9][9] = { false };
	bool block[9][9] = { false };

public:

	void solveSudoku(vector<vector<char>>& board) {
		init(board);
		dfs(board, 0);
	}

	void init(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				char ch = board[i][j];
				if (ch != '.') {
					row[i][ch - '1'] = true;
					col[j][ch - '1'] = true;
					block[i / 3 * 3 + j / 3][ch - '1'] = true;
				}
			}
		}
	}

	bool dfs(vector<vector<char>>& board, int index) {
		if (index == 81) return true;
		int x = index / 9, y = index % 9;
		if (board[x][y] != '.') return dfs(board, index + 1);
		for (int i = 0; i < 9; ++i) {
			board[x][y] = i + '1';
			if (!row[x][i] && !col[y][i] && !block[x / 3 * 3 + y / 3][i]) {
				row[x][i] = true;
				col[y][i] = true;
				block[x / 3 * 3 + y / 3][i] = true;
				if (dfs(board, index + 1)) return true;
				row[x][i] = false;
				col[y][i] = false;
				block[x / 3 * 3 + y / 3][i] = false;
			}
			board[x][y] = '.';
		}
		return false;
	}
};
