//207. Course Schedule
//Medium
//DAG(������Ȧͼ)���� BFS
//�����ڽ�����

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		if (prerequisites.empty()) return true;
		if (2 * (int)prerequisites.size() > numCourses*(numCourses - 1)) return false;
		vector<unordered_set<int>> adjacencyList(numCourses);
		makeGraph(prerequisites, adjacencyList);
		vector<int> indegree(numCourses, 0);	//���
		calculateIndegree(adjacencyList, indegree);
		int n = numCourses;
		while (n--) {		//һ��numCourses���㣬��Щ�ֹ������ȫ�����
			int i = 0;
			for (; i < numCourses; i++) {
				if (indegree[i] == 0) break;
			}
			if (i == numCourses) return false;  //û��һ�������Ϊ0
			indegree[i] = -1;
			//ȥ�������֮�󣬸�������������
			for (int j : adjacencyList[i]) {
				indegree[j]--;
			}
		}
		return true;
	}
private:
	static void makeGraph(vector<pair<int, int>>& prerequisites, vector<unordered_set<int>>& adjList) {
		for (auto it : prerequisites) {
			adjList[it.second].insert(it.first);
		}
	}
	static void calculateIndegree(vector<unordered_set<int>>& adjList,vector<int>& indegree) {
		for (auto it : adjList) {
			for (int i : it) {
				indegree[i]++;
			}
		}
	}
};

#if 0
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
#endif