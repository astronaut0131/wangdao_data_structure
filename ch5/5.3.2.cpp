#include "graph.hpp"
#include <vector>
using std::vector;

template <class T>
bool isTree(const Graphlnk<T>& g) {
	vector<bool> visit(g.NumberOfVertices(),false);
	int node_num = 0, edge_num = 0;
	DFS(0,node_num,edge_num,visit,g);
	return node_num == g.NumberOfVertices() && edge_num == 2*(g.NumberOfVertices()-1);
}
template <class T>
void DFS(int index,int& node_num, int& edge_num, vector<bool>& visit,const Graphlnk<T>& g) {
	visit[index] = true;
	node_num++;
	auto p = g.getFirstNeighbor(index);
	while (p!=-1) {
		edge_num++;
		if (!visit[p])
			DFS(p,node_num,edge_num,visit,g);
		p = g.getNextNeighbor(index,p);
	}
}

int main() {
	Graphlnk<int> g;
	g.generateTestData();
	Graphlnk<int> h;
	h.generateTestData(true);
	cout << isTree(g) << endl;
	cout << isTree(h) << endl;
	return 0;
}