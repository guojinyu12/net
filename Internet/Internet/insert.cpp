#include"Graphlink.h"
inline bool Graphlink::insertEdge(int vertex1, int vertex2,int cost)
{
	int v1 = getVertexPos(vertex1);
	int v2 = getVertexPos(vertex2);
	Table[v1].adj = new Edge(v2, cost, Table[v1].adj);
	if(Table[v1].adj==nullptr)
		return false;
	++numEdges;
	return true;
}

inline bool Graphlink::insertVertex(const int& vertex) {//插入一个顶点
	if (numVertices < maxVertices) {
		Table[numVertices].data = vertex;
		++numVertices;
		return true;
	}
	return false;
}
