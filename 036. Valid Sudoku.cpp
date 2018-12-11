//36. Valid Sudoku
//Medium
//穷举

#include <vector>
using namespace std;

class Solution {
public:
	/*****************
	bool isValidSudoku1(vector<vector<char>>& board) {
		for (int i = 0; i < 9; i++) {   //检验每行
			int available[9] = { 0 };
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.') continue;
				int digit = board[i][j] - '0';
				if (available[digit - 1] == 0) {
					available[digit - 1] = 1;
				}
				else return false;
			}
		}

		for (int j = 0; j < 9; j++) {   //检验每列
			int available[9] = { 0 };
			for (int i = 0; i < 9; i++) {
				if (board[i][j] == '.') continue;
				int digit = board[i][j] - '0';
				if (available[digit - 1] == 0) {
					available[digit - 1] = 1;
				}
				else return false;	
			}
		}

		for (int i = 0; i < 9; i = i + 3) {    //检验每个3×3
			for (int j = 0; j < 9; j = j + 3) {
				int available[9] = { 0 };
				for (int t = 0; t < 3; t++) {
					for (int p = 0; p < 3; p++) {
						if (board[i + t][j + p] == '.') continue;
						int digit = board[i + t][j + p] - '0';
						if (available[digit - 1] == 0) {
							available[digit - 1] = 1;
						}
						else return false;
					}
				}
			}
		}
		return true;
	}
	******************/

	bool isValidSudoku(vector<vector<char>>& board) {
		const int n = 9;
		vector<vector<bool>> row(n, vector<bool>(n, false));
		vector<vector<bool>> col(n, vector<bool>(n, false));
		vector<vector<bool>> block(n, vector<bool>(n, false));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				char ch = board[i][j];
				if (ch == '.') continue;
				int idx = ch - '1';
				if (row[i][idx]) return false;
				if (col[j][idx]) return false;
				if (block[i / 3 * 3 + j / 3][idx]) return false;
				row[i][idx] = true;
				col[j][idx] = true;
				block[i / 3 * 3 + j / 3][idx] = true;
			}
		}
		return true;
	}
};