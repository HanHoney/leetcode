//210. Course Schedule II
//Medium
//拓扑序列 DAG
//相关题目 207

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> ret;
		if (2 * (int)prerequisites.size()>numCourses*(numCourses - 1)) {
			return ret;
		}
		if (prerequisites.empty()) {
			for (int i = 0; i<numCourses; i++) {
				ret.push_back(i);
			}
			return ret;
		}
		vector<unordered_set<int>> adjList(numCourses);
		vector<int> indegree(numCourses, 0);
		makeGraph(prerequisites, adjList);
		calculateIndegree(adjList, indegree);
		int n = numCourses;
		while (n--) {
			int i = 0;
			for (; i<numCourses; i++) {
				if (indegree[i] == 0) {
					ret.push_back(i);
					indegree[i] = -1;
					break;
				}
			}
			if (i == numCourses) {
				return vector<int>{};
			}
			for (auto j : adjList[i]) {
				indegree[j]--;
			}
		}
		return ret;
	}
private:
	static void makeGraph(vector<pair<int, int>> prerequisites, vector<unordered_set<int>>& adjList) {
		for (auto it : prerequisites) {
			adjList[it.second].insert(it.first);
		}
	}
	static void calculateIndegree(vector<unordered_set<int>> adjList, vector<int>& indegree) {
		for (auto it : adjList) {
			for (auto i : it) {
				indegree[i]++;
			}
		}
	}
};