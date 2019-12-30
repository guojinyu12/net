#include"Graph.h"
bool Graphlink::insertEdge(int vertex1, int vertex2, int cost)//������
{
	int v1 = getVertexPos(vertex1);
	int v2 = getVertexPos(vertex2);
	Table[v1].adj = new Edge(v2, cost, Table[v1].adj);
	if (Table[v1].adj == nullptr)
		return false;
	++numEdges;
	return true;
}
bool Graphlink::insertVertex(const int& vertex) {//����һ������
	if (numVertices < maxVertices) {
		Table[numVertices].data = vertex;
		++numVertices;
		return true;
	}
	return false;
}
ostream& operator << (ostream& os, Graphlink& G) {//����
	Edge* p = nullptr;
	for (int i = 0; i < G.numVertices; i++) {
		os << G.Table[i] << endl;
		p = G.Table[i].adj;//��ʼ��
		while (p != nullptr) {
			os << G.Table[i] << "  " << G.Table[p->dest]
				<< "  " << p->cost << endl;
			p = p->link;//����
		}
		cout << endl;
	}
	return os;
}