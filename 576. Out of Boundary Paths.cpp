//576. Out of Boundary Paths
//Medium

#include <iostream>
#include <vector>
using namespace std;

class Solution {
	int mod = 1e9 + 7;
	int steps[4][2] = {
		{0,1},
		{0,-1},
		{1,0},
		{-1,0}
	};
public:
	//dp
	//dp[i][j][k] = dp[i - 1][j][k - 1] + dp[i + 1][j][k - 1] + dp[i][j - 1][k - 1] + dp[i][j + 1][k - 1]
	//dp[i][j][0] = 0;

	int findPaths(int m, int n, int N, int i, int j) {
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int k = 1; k <= N; ++k) {
			vector<vector<int>> tmp(m, vector<int>(n, 0));
			for (int x = 0; x < m; ++x) {
				for (int y = 0; y < n; ++y) {
					for (int z = 0; z < 4; ++z) {
						int dx = x + steps[z][0];
						int dy = y + steps[z][1];
						if (dx < 0 || dx >= m || dy < 0 || dy >= n) {
							++tmp[x][y];
						}
						else {
							tmp[x][y] = (tmp[x][y] + dp[dx][dy]) % mod;
						}
					}
				}
			}
			dp = tmp;
		}
		return dp[i][j] % mod;
	}
	/*
	//TLE
	void dfs(int&ret,int x,int y,int m,int n,int N){
		if(N<0) return;
		if(x<0||x>=m||y<0||y>=n){
			ret=(ret+1)%mod;
			return;
		}
		for(int i=0;i<4;++i){
			dfs(ret,x+steps[i][0],y+steps[i][1],m,n,N-1);
		}
	}
	*/
};