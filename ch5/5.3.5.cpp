#include "graph.hpp"
#include <vector>
#include <stack>
#include <queue>
using std::vector;
using std::stack;
using std::queue;

template <class T>
void findAllPath(const Graphlnk<T>& g,int v,int target, vector<T>& path,
			     vector<bool>& visit) {
	visit[v] = true;
	path.push_back(g.getValue(v));
	if (v == target) {
		for (auto node:path) {
			cout << node << " ";
		}
		cout << endl;
	} else {
		for (int i = g.getFirstNeighbor(v); i != -1; i = g.getNextNeighbor(v,i)) {
			if (!visit[i]) {
				findAllPath(g,i,target,path,visit);
			}
		}
	}
	path.pop_back();
	visit[v] = false;
}

int main() {
	Graphlnk<int> g;
	g.generateTestData();
	Graphlnk<int> h;
	h.generateTestData(true);
	Graphlnk<int> i;
	i.generateTestData2(true);
	vector<bool> visit(g.NumberOfVertices(),false);
	vector<int> path;
	findAllPath(g,0,1,path,visit);
	visit.clear();
	findAllPath(h,0,1,path,visit);
	vector<bool> visit2(i.NumberOfVertices(),false);
	path.clear();
	findAllPath(i,0,4,path,visit2);
	return 0;
}