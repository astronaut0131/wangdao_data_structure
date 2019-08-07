#include "graph.hpp"
#include <vector>
#include <stack>
#include <queue>
using std::vector;
using std::stack;
using std::queue;

template <class T>
bool DFS(int v,int target,const Graphlnk<T>& g, vector<bool>& visit) {
	if (v == target) return true;
	visit[v] = true;
	bool has = false;
	for (int i = g.getFirstNeighbor(v); i != -1; i = g.getNextNeighbor(v,i)) {
		if (!visit[i]) {
			has |= DFS(i,target,g,visit);
			if (has) return true;
		}
	}
	return false;
}

template <class T>
bool BFS(int v,int target,const Graphlnk<T>& g) {
	if (g.NumberOfVertices() == 0) return false;
	queue<int> q;
	q.push(v);
	vector<bool> visit(g.NumberOfVertices(),false);
	while (!q.empty()) {
		auto front = q.front();
		if (front == target) return true;
		q.pop();
		visit[front] = true;
		for (int i = g.getFirstNeighbor(front); i != -1; i = g.getNextNeighbor(front,i)) {
			if (!visit[i]) {
				q.push(i);
			}
		}
	}
	return false;
}

int main() {
	Graphlnk<int> g;
	g.generateTestData();
	Graphlnk<int> h;
	h.generateTestData(true);
	Graphlnk<int> i;
	i.generateTestData2(false);
	vector<bool> visit(g.NumberOfVertices(),false);
	cout << DFS(1,2,g,visit) << endl;
	cout << BFS(1,2,g) << endl;
	visit.clear();
	cout << DFS(1,2,h,visit) << endl;
	cout << BFS(1,2,h) << endl;
	vector<bool> visit2(i.NumberOfVertices(),false);
	cout << DFS(0,4,i,visit2) << endl;
	cout << BFS(0,4,i) << endl;
	return 0;
}