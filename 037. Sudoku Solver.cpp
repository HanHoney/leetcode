//37. Sudoku Solver
//Hard
//DFS

#include <vector>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		DFS(board, 0);
	}

private:
	bool DFS(vector<vector<char>>& board,int pos) {
		if (pos >= 81) return true;
		int row = pos / 9;
		int col = pos % 9;
		if (board[row][col] != '.') {
			return DFS(board, pos + 1);
		}
		for (int i = 1; i <= 9; i++) {
			board[row][col] = i + '0';
			if (isValid(board, row, col) && DFS(board, pos + 1)) {
				return true;
			}
			board[row][col] = '.';
		}
		return false;
	}
	bool isValid(vector<vector<char>>& board,int row,int col) {
		for (int j = 0; j < 9; j++) {
			if (j != col && board[row][j] == board[row][col])
				return false;
		}
		for (int i = 0; i < 9; i++) {
			if (i != row && board[i][col] == board[row][col])
				return false;
		}
		for (int i = row / 3 * 3; i < row / 3 * 3 + 3; i++) {
			for (int j = col / 3 * 3; j < col / 3 * 3 + 3; j++) {
				if ((i != row || j != col) && board[i][j] == board[row][col])
					return false;
			}
		}
		return true;
	}
};

