#include "graph.hpp"
#include <vector>
#include <stack>
using std::vector;
using std::stack;
template <class T>
void DFS(const Graphlnk<T>& g,int start) {
	if (g.NumberOfVertices() == 0 || start < 0 || start >= g.NumberOfVertices()) return;
	vector<bool> visited(g.NumberOfVertices(),false);
	stack<T> s;
	s.push(start);
	visited[start] = true;
	cout << g.getValue(start) << " ";
	while (!s.empty()) {
		auto top = s.top();
		int i = g.getFirstNeighbor(top);
		for (; i != -1; i = g.getNextNeighbor(top,i)) {
			if (!visited[i]) {
				cout << g.getValue(i) << " ";
				visited[i] = true;
				s.push(i);
				break;
			}
		}
		if (i == -1) s.pop();
	}
}

int main() {
	Graphlnk<int> g;
	g.generateTestData();
	Graphlnk<int> h;
	h.generateTestData(true);
	Graphlnk<int> i;
	i.generateTestData2();

	DFS(g,0);
	cout << endl;
	DFS(h,0);
	cout << endl;
	DFS(i,0);
	return 0;
}