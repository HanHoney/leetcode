//289. Game of Life
//Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//0->1 recorded as 'l'
	//1->0 recorded as 'd'
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty() || board[0].empty()) return;
		m = board.size();
		n = board[0].size();
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				change(i, j, board);
			}
		}
		for (int i = 0; i<m; i++) {
			for (int j = 0; j<n; j++) {
				if (board[i][j] == 'l') {
					board[i][j] = 1;
				}
				if (board[i][j] == 'd') {
					board[i][j] = 0;
				}
			}
		}
	}
	void change(int x, int y, vector<vector<int>>& board) {
		int live = 0;
		for (int i = 0; i<8; i++) {
			int px = x + steps[i][0];
			int py = y + steps[i][1];
			if (px<0 || px >= m || py<0 | py >= n) {
				continue;
			}
			if (board[px][py] == 1 || board[px][py] == 'd') {
				live++;
			}
		}
		if (board[x][y] == 1 && (live<2 || live>3)) {
			board[x][y] = 'd';
		}
		else if (live == 3 && board[x][y] == 0) {
			board[x][y] = 'l';
		}
	}
private:
	int m;
	int n;
	int steps[8][2] = {
		{ -1,-1 },
	{ -1,0 },
	{ -1,1 },
	{ 0,-1 },
	{ 0,1 },
	{ 1,-1 },
	{ 1,0 },
	{ 1,1 }
	};
};