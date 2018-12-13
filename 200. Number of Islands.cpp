//200. Number of Islands
//Medium
//DFS

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0) return 0;
		int res = 0;
		int row = grid.size();
		int col = grid[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == '1') {
					res++;
					dfs(grid, i, j);
				}
			}
		}
		return res;
	}
private:
	//必须扩展周围四个点，不能只向下向右走，递归会改变原本的行列遍历顺序。
	//for instance：工字型岛屿
	static void dfs(vector<vector<char>>& grid, int x, int y) {
		int row = grid.size();
		int col = grid[0].size();
		if (x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == '0') return;	//遇到water停止递归
		grid[x][y] = '0';	//visited，否则死循环
		dfs(grid, x - 1, y);
		dfs(grid, x + 1, y);
		dfs(grid, x, y - 1);
		dfs(grid, x, y + 1);
	}
};


int main() {
	vector<vector<char>> grid1{
	{'1','1','1','1','0'},
	{'1','1','0','1','0'},
	{'1','1','0','0','0'},
	{'0','0','0','0','0'},
	};
	vector<vector<char>> grid2{
	{ '1','1','0','0','0' },
	{ '1','1','0','0','0' },
	{ '0','0','1','0','0' },
	{ '0','0','0','1','1' },
	};
	Solution s;
	cout << s.numIslands(grid1) << endl;
	cout << s.numIslands(grid2) << endl;
	system("pause");
	return 0;
}