//130. Surrounded Regions
//Medium
//DFS

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	int m;
	int n;
	int step[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
public:
	void solve(vector<vector<char>>& board) {
		m = board.size();
		if (m == 0) return;
		n = board[0].size();
		for (int i = 0; i < n; i++) {      //�ӱ�Ե��dfs���ڲ�����
			dfs(board, 0, i);
			dfs(board, m - 1, i);
		}
		for (int i = 0; i < m; i++) {
			dfs(board, i, 0);
			dfs(board, i, n - 1);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'O') {   //��������'O'�����'X'
					board[i][j] = 'X';
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 'R') {   //Ҫ������'O'�ָ�
					board[i][j] = 'O';
				}
			}
		}
	}
	void dfs(vector<vector<char>>& board, int x, int y) {
		if (x < 0 || x >= m || y < 0 || y >= n) return;
		if (board[x][y] != 'O') return;
		board[x][y] = 'R';    //������б�����'O'���ȼǳ�'R'
		for (int i = 0; i < 4; i++) {
			int px = x + step[i][0];
			int py = y + step[i][1];
			dfs(board, px, py);
		}
	}
};