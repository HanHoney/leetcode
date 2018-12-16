//207. Course Schedule
//Medium
//DAG(有向无圈图)问题 BFS
//采用邻接链表

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (prerequisites.empty()) return true;
		vector<unordered_set<int>> adjacencyList(numCourses, unordered_set<int>{});
		makeGraph(numCourses, prerequisites, adjacencyList);
		vector<int> indegree(numCourses, 0);	//入度
		calculateIndegree(adjacencyList, indegree);
		int n = numCourses;
		while (n--) {		//一共numCourses个点，这些轮过后才能全部输出
			int j = 0;
			for (; j < numCourses; j++) {
				if (indegree[j] == 0) break;
			}
			if (j == numCourses) return false;  //没有一个点入度为0
			indegree[j] = -1;
			//去掉这个点之后，更新其他点的入度
			for (int k : adjacencyList[j]) {
				indegree[k]--;
			}
		}
		return true;
	}
private:
	static void makeGraph(int numCourses, vector<pair<int, int>>& prerequisites, vector<unordered_set<int>>& graph) {
		for (auto it : prerequisites) {
			graph[it.second].insert(it.first);
		}
	}
	static void calculateIndegree(vector<unordered_set<int>>& graph,vector<int>& indegree) {
		for (auto it : graph) {
			for (int i : it) {
				indegree[i]++;
			}
		}
	}
};

int main() {
	int num = 5;
	vector<pair<int, int>> pre1{ { 1,0 },{ 2,0 },{ 2,1 },{ 3,2 },{ 4,3 } };
	vector<pair<int, int>> pre2{ { 1,0 },{ 2,0 },{ 2,1 },{ 3,2 },{ 2,3 } };
	Solution s;
	cout << s.canFinish(num, pre1) << endl;
	cout << s.canFinish(num, pre2) << endl;
	system("pause");
	return 0;
}
