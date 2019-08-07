#include <iostream>
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
const int DefaultVertices = 30;
template <class T>
class Graph {
public:
	Graph(int sz = DefaultVertices):maxVertices(sz),numVertices(0),numEdges(0) {};
	virtual ~Graph() {};
	bool GraphEmpty() const {
		return numEdges == 0;
	}
	bool GraphFull() const {
		return numVertices == maxVertices || numEdges == maxVertices * (maxVertices - 1) / 2;
	}
	int NumberOfVertices() const {
		return numVertices;
	}
	int NumberOfEdges() const {
		return numEdges;
	}
	virtual T getValue(int i) const = 0;
	virtual int getFirstNeighbor(int v) const = 0;
	virtual int getNextNeighbor(int v,int w) const = 0;
	virtual bool insertVertex(const T& vertex) = 0;
	virtual bool insertEdge(int v1,int v2) = 0;
	virtual bool removeEdge(int v1,int v2) = 0;
	virtual bool removeVertex(int v) = 0;
	virtual void generateTestData(bool cyclic) = 0;
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
	virtual int getVertexPos(T vertex) = 0;
};

template <class T>
struct Edge{
	int dest;
	Edge<T> *link;
	Edge() {}
	Edge(int num):dest(num),link(nullptr) {}
	bool operator != (Edge<T>& R) const {
		return dest != R.dest;
	}
};

template <class T>
struct Vertex{
	T data;
	Edge<T> *adj;
};

template <class T>
class Graphlnk : public Graph<T>{
	friend istream& operator >> (istream& in, Graphlnk<T>& G);
	friend ostream& operator << (ostream& out, Graphlnk<T>& G);
public:
	Graphlnk(int sz = DefaultVertices);
	~Graphlnk();
	T getValue(int i) const override{
		return (i >= 0 && i < this->numVertices) ? NodeTable[i].data : 0;
	}
	int getFirstNeighbor(int v) const override;
	int getNextNeighbor(int v,int w) const override;
	bool insertVertex(const T& vertex) override;
	bool insertEdge(int v1,int v2) override;
	bool removeEdge(int v1,int v2) override;
	bool removeVertex(int v) override;
	void generateTestData(bool cyclic = false) override;
	void generateTestData2(bool connected = true);
private:
	Vertex<T> *NodeTable;
	int getVertexPos(const T vertex) override{
		for (int i = 0; i < this->numVertices; i++) {
			if (NodeTable[i].data == vertex) return i;
		}
		return -1;
	}
};

template <class T>
void Graphlnk<T>::generateTestData2(bool connected) {
	if (connected) {
		/*
		 *          4 - 5
		 *        / 
		 *		1 - 2 - 3
		 *
		 *
		 *
		 */
		insertVertex(1);
		insertVertex(2);
		insertVertex(3);
		insertVertex(4);
		insertVertex(5);
		insertEdge(0,1);
		insertEdge(1,2);
		insertEdge(0,3);
		insertEdge(3,4);
	} else {
		insertVertex(1);
		insertVertex(2);
		insertVertex(3);
		insertVertex(4);
		insertVertex(5);
	}

}

template <class T>
void Graphlnk<T>::generateTestData(bool cyclic) {
	insertVertex(1);
	insertVertex(2);
	insertVertex(3);
	insertVertex(4);
	if (cyclic) {
		/* 3
		  / \
		1 -- 2
          \ /
           4

		*/
		insertEdge(0,1);
		insertEdge(0,2);
		insertEdge(0,3);
		insertEdge(1,3);
		insertEdge(1,2);
	} else {
		/* 
		   3
		  / 
		1 -- 2
          \ 
           4
		*/
		insertEdge(0,1);
		insertEdge(0,2);
		insertEdge(0,3);
	}

}

template <class T>
Graphlnk<T>::Graphlnk(int sz):Graph<T>(sz) {
	NodeTable = new Vertex<T>[this->maxVertices];
	if (!NodeTable) cout << "allocation node table failed" << endl;
	for (int i = 0; i < this->maxVertices; i++) NodeTable[i].adj = nullptr;
}

template <class T>
Graphlnk<T>::~Graphlnk(){
	for (int i = 0; i < this->numVertices;i++) {
		Edge<T> *p = NodeTable[i].adj;
		while (p) {
			NodeTable[i].adj = p->link;
			delete p;
			p = NodeTable[i].adj;
		}
	}
	delete [] NodeTable;
}

template <class T>
int Graphlnk<T>::getFirstNeighbor(int v) const{
	if (v >= 0 && v < this->maxVertices) {
		Edge<T> *p = NodeTable[v].adj;
		if (p) return p->dest;
	}
	return -1;
}

template <class T>
int Graphlnk<T>::getNextNeighbor(int v,int w) const{
	if (v >= 0 && v < this->maxVertices) {
		Edge<T> *p = NodeTable[v].adj;
		while (p != nullptr && p->dest != w) {
			p = p->link;
		}
		if (p != nullptr && p->link != nullptr)
			return p->link->dest;
	}
	return -1;
}

template <class T>
bool Graphlnk<T>::insertVertex(const T& vertex) {
	if (this->numVertices == this->maxVertices) return false;
	NodeTable[this->numVertices].data = vertex;
	this->numVertices++;
	return true;
}

template <class T>
bool Graphlnk<T>::removeVertex(int v) {
	if (this->numVertices == 1 || v < 0 || v >= this->numVertices) return false;
	Edge<T> *p,*s,*t;
	int i,k;
	while (NodeTable[v].adj != nullptr) {
		p = NodeTable[v].adj;
		k = p->dest;
		s = NodeTable[k].adj;
		t = nullptr;
		while (s != nullptr && s->dest != v) {
			t = s;
			s = s->link;
		}
		if (s != nullptr) {
			if (t == nullptr) NodeTable[k].adj = s->link;
			else t->link = s->link;
			delete s;
		}
		NodeTable[v].adj = p->link;
		delete p;
		this->numEdges--;
	}
	this->numVertices--;
	NodeTable[v].data = NodeTable[this->numVertices].data;
	p = NodeTable[v].adj = NodeTable[this->numVertices].adj;
	while (p != nullptr) {
		s = NodeTable[p->dest].adj;
		while (s != nullptr) {
			if (s->dest == this->numVertices) {
				s->dest = v;
				break;
			}
			else {
				s = s->link;
			}
		}
		p = p->link;
	}
	return true;
}

template <class T>
bool Graphlnk<T>::insertEdge(int v1,int v2) {
	if (v1 >= 0 && v1 < this->numVertices && v2 >= 0 && v2 < this->numVertices) {
		Edge<T> *q, *p = NodeTable[v1].adj;
		while (p != nullptr && p->dest != v2)
			p = p->link;
		if (p != nullptr) return false;
		p = new Edge<T>;
		q = new Edge<T>;
		p->dest = v2;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;
		q->dest = v1;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		this->numEdges++;
		return true;
	}
	return 0;
}

template <class T>
bool Graphlnk<T>::removeEdge(int v1,int v2) {
	if (v1 >= 0 && v1 < this->numVertices && v2 >= 0 && v2 < this->numVertices) {
		Edge<T> *p = NodeTable[v1].adj,*q = nullptr,*s = p;
		while (p != nullptr && p->dest != v2) {
			q = p; p = p->link;
		}
		if (p != nullptr) {
			if (p == s) NodeTable[v1].adj = p->link;
			else q->link = p->link;
			delete p;
		}
		else return false;
		p = NodeTable[v2].adj;
		q = nullptr;
		s = p;
		while (p->dest != v1){
			q = p; p = p->link;
		}
		if (p != nullptr) {
			if (p == s) NodeTable[v2].adj = p->link;
			else q->link = p->link;
			delete p;
		}
		return true;

	}
	return false;
}

template <class T>
class Graphmtx: public Graph<T>{
	friend istream& operator >> (istream& in, Graphmtx<T>& G);
	friend ostream& operator << (ostream& out, Graphmtx<T>& G);
public:
	Graphmtx(int sz = DefaultVertices);
	~Graphmtx() {
		delete []VerticesList;
		delete []Edge;
	}
	T getValue(int i) const override{
		return i >= 0 && i <= this->numVertices ? VerticesList[i] : NULL;
	}
	int getFirstNeighbor(int v) const override;
	int getNextNeighbor(int v,int w) const override;
	bool insertVertex(const T& vertex) override;
	bool insertEdge(int v1,int v2) override;
	bool removeEdge(int v1,int v2) override;
	bool removeVertex(int v) override;
	void generateTestData(bool cyclic = false) override;

private:
	T * VerticesList;
	int **Edge;
	int getVertexPos(T vertex) override {
		for (int i = 0; i < this->numVertices; i++) {
			if (VerticesList[i] == vertex) return i;
		}
		return -1;
	}
};

template <>
void Graphmtx<int>::generateTestData(bool cyclic) {
	insertVertex(1);
	insertVertex(2);
	insertVertex(3);
	insertVertex(4);
	if (cyclic) {
		/* 3
		  / \
		1 -- 2
          \ /
           4

		*/
		insertEdge(0,1);
		insertEdge(0,2);
		insertEdge(0,3);
		insertEdge(1,3);
		insertEdge(1,2);
	} else {
		/* 
		   3
		  / 
		1 -- 2
          \ 
           4
		*/
		insertEdge(0,1);
		insertEdge(0,2);
		insertEdge(0,3);
	}
}

template <class T>
Graphmtx<T>::Graphmtx(int sz):Graph<T>(sz) {
	VerticesList = new T[this->maxVertices];
	Edge = (int **) new int *[this->maxVertices];
	for (int i = 0;i < this->maxVertices; i++) {
		Edge[i] = new int[this->maxVertices];
	}
	for (int i = 0;i < this->maxVertices; i++) {
		for (int j = 0; j < this->maxVertices; j++) {
			Edge[i][j] = 0;
		}
	}
}

template <class T>
int Graphmtx<T>::getFirstNeighbor(int v) const{
	if (v >= 0 && v < this->maxVertices) {
		for (int col = 0; col < this->maxVertices; col++) {
			if (Edge[v][col]) return col;
		}
	}
	return -1;
}

template <class T>
int Graphmtx<T>::getNextNeighbor(int v,int w) const{
	if (v >= 0 && v < this->maxVertices) {
		for (int col = w+1;col < this->maxVertices; col++){
			if (Edge[v][col]) return col;
		}
	}
	return -1;
}

template <class T>
bool Graphmtx<T>::insertVertex(const T& vertex) {
	if (this->numVertices == this->maxVertices) return false;
	VerticesList[this->numVertices++] = vertex;
	return true;
}

template <class T>
bool Graphmtx<T>::removeVertex(int v) {
	if (v < 0 || v > this->numVertices) return false;
	if (this->numVertices == 1) return false;
	VerticesList[v] = VerticesList[this->numVertices-1];
	for (int i = 0; i < this->numVertices; i++) {
		Edge[i][v] = Edge[i][this->numVertices-1];
		if (Edge[i][v]) this->numEdges--;
	}
	this->numVertices--;
	for (int j = 0; j < this->numVertices; j++) {
		Edge[v][j] = Edge[this->numVertices][j];
	}
	return true;
}

template <class T>
bool Graphmtx<T>::insertEdge(int v1,int v2) {
	if (v1 >= 0 && v1 < this->numVertices && v2 >= 0 && v2 < this->numVertices && Edge[v1][v2] == 0){
		Edge[v1][v2] = Edge[v2][v1] = 1;
		this->numEdges++;
		return true;
	}
	return false;
}

template <class T>
bool Graphmtx<T>::removeEdge(int v1,int v2) {
	if (v1 >= 0 && v1 < this->numVertices && v2 >= 0 && v2 < this->numVertices && Edge[v1][v2]) {
		Edge[v1][v2] = Edge[v2][v1] = 0;
		this->numEdges--;
		return true;
	}
	return false;
}

template <class T>
istream& operator >> (istream& in, Graphmtx<T>& G) {
	int n,m;
	in >> n >> m;
	T e1,e2;
	int i;
	for (i = 0; i < n; i++) {
		in >> e1;
		G.insertVertex(e1);
	}
	i = 0;
	while (i < m) {
		in >> e1 >> e2;
		if (G.getVertexPos(e1) == -1 || G.getVertexPos(e2) == -1) {
			cout << "invalid edge, input again!" << endl;
		} else {
			G.insertEdge(e1,e2);
			i++;
		}
	}
	return in;
}

template <class T>
ostream& operator << (ostream& out, Graphmtx<T>& G) {
	int i,j;
	T e1,e2;
	int n,m;
	n = G.NumberOfVertices(); m = G.NumberOfEdges();
	out << n << "," << m << endl;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (G.Edge[i][j])
				out << "(" << i << "," << j << ")" << endl;
		}
	}
}